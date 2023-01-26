#include "parser.hpp"
#include <stdexcept>

using tokenArray = Parser::tokenArray;
using structureArray = Parser::structureArray;

structureArray Parser::parse(tokenArray& tokens) {
	currToken = tokens.begin();
	endToken =tokens.end();
	structureArray res;
	
	while ( currToken != endToken ) {
		if(currToken->type == FUNCTION) {
			Structure* curr = expectFunctionDeclaration(currToken);
			res.push_back(curr);
		}
		currToken++;
	}
	return res;
}

Structure* Parser::expectFunctionDeclaration(tokenArray::iterator& currToken) {
	if(currToken->type == FUNCTION)
		currToken++;
	FunctionDeclaration* newFunc = new FunctionDeclaration();
	newFunc->name = currToken->text;
	currToken++;
	if(currToken->type != L_PARENT)
		throw std::runtime_error("Invalid function parameter declaration");
	
	newFunc->parameters = parseParameters(currToken);
	//to here
	std::vector<enum TokenType> endBody;
	endBody.push_back(END);

	newFunc->body = parseBody(currToken, endBody);
	/* newFunc->returnType = determineFunctionReturnType(newFunc->body); */
	return newFunc;
}
Structure* Parser::expectFunctionCall(tokenArray::iterator& currToken) {
	FuncCall* fCall = new FuncCall();
	if(currToken->type != IDENTIFIER) {
		throw std::runtime_error("Unknown functionCall name");
	}
	fCall->name = currToken->text;
	currToken++;
	fCall->parameters = parseParameters(currToken);
	return fCall;
}
Structure* Parser::expectVariableDeclaration(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectVariableCall(tokenArray::iterator& currToken) {
	VariableCall* var = new VariableCall();
	var->name = currToken->text;
	currToken++;
	return var;
}
Structure* Parser::expectElem(tokenArray::iterator& currToken) {
	Element* elem = new Element();
	
	if(currToken->type == NUMBER_LITERAL) {
		elem->kind = NUM_LITERAL;
		elem->returnType = DOUBLE;
	} else if(currToken->type == STRING_LITERAL) {
		elem->kind = STR_LITERAL;
		elem->returnType = STRING;
	} else if(isOperator(currToken))
		elem->kind = OPERATOR;
	
	elem->text = currToken->text;
	currToken++;
	return elem;
}
Structure* Parser::expectTable(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectReturn(tokenArray::iterator& currToken) {
	return nullptr;
}

std::vector<structureArray> Parser::parseParameters(tokenArray::iterator& currToken) {
	std::vector<structureArray> arr;
	structureArray curr; 
	if(currToken->type == L_PARENT)
		currToken++;
	
	while (currToken->type != R_PARENT) {
		if(currToken->type == COMMA) {
			arr.push_back(curr);
			curr.clear();
		} else if(currToken->type == IDENTIFIER) {
			curr.push_back(parseID(currToken)); //currToken moved inside
		} else if(isOperator(currToken) || isLiteral(currToken)) {
			curr.push_back(expectElem(currToken)); //currToken moved inside
		} else {
			throw std::runtime_error("Unhandled case inside parameters");
			currToken++;
		}
	}
	currToken++;
	arr.push_back(curr);
	return arr;
}

Structure* Parser::parseID(tokenArray::iterator& currToken) {
	std::string name = currToken->text;
	currToken++;
	if(currToken->type == L_PARENT) { //functionCall
		currToken--;
		return expectFunctionCall(currToken);
	} else if(currToken->type == L_BRACKET) { //table call
		currToken--;
		return expectTable(currToken);
	} else if(currToken->type == ASSIGN) { //variable declaration !!!! or table declaration
		currToken++;
		if(currToken->type == L_BRACE) {
			//table declaration
			throw std::runtime_error("Tables are not currently supported");
		}
		currToken--;
		currToken--;
		return expectVariableDeclaration(currToken);
	} else { //variable
		currToken--;
		return expectVariableCall(currToken);
	}
	throw std::runtime_error("Unknown identifier");
	//keywords?
}

structureArray Parser::parseBody(tokenArray::iterator& currToken, std::vector<enum TokenType> endBody) {
	structureArray body;
	while (!isEndBodyToken(currToken, endBody)) {
		//parse for every structure
		if(currToken->type == IDENTIFIER) {
			Structure* newID = parseID(currToken); // supporting -> VariableCall, FuncCall, VariableDeclaration, tableCall, tableDeclaration
			body.push_back(newID);
		/* } else if(currToken->type == RETURN) { */ // to-do -> elem?, if, else, while, return 
		} else {
			/* throw std::runtime_error("Invalid structure inside body"); */
			currToken++;
		}
	}
	return body;
}
bool Parser::isOperator(tokenArray::iterator& currToken) {

	if (
		currToken->type == PLUS ||
		currToken->type == L_PARENT ||
		currToken->type == R_PARENT ||
		currToken->type == L_BRACE ||
		currToken->type == R_BRACE ||
		currToken->type == L_BRACKET ||
		currToken->type == R_BRACKET ||
		currToken->type == PLUS ||
		currToken->type == MINUS ||
		currToken->type == STAR ||
		currToken->type == PERCENT ||
		currToken->type == EXP ||
		currToken->type == SH ||
		currToken->type == ASSIGN ||
		currToken->type == EQUAL ||
		currToken->type == LESS_OR_EQUAL ||
		currToken->type == GREATER_OR_EQUAL ||
		currToken->type == NOT_EQUAL ||
		currToken->type == LESS_THAN ||
		currToken->type == DOUBLE_LESS_THAN ||
		currToken->type == GREATER_THAN ||
		currToken->type == DOUBLE_GREATER_THAN ||
		currToken->type == SLASH ||
		currToken->type == DOUBLE_SLASH ||
		currToken->type == TILDE ||
		currToken->type == COLON ||
		currToken->type == DOUBLE_COLON ||
		currToken->type == SEMI_COLON ||
		currToken->type == DOT ||
		currToken->type == DOUBLE_DOT ||
		currToken->type == ELLIPSIS ||
		currToken->type == AMPERSAND ||
		currToken->type == AND ||
		currToken->type == OR ||
		currToken->type == PIPE ) 
	{
		return true;
	}
	return false;
}

bool Parser::isLiteral(tokenArray::iterator& currToken) {
	return currToken->type == NUMBER_LITERAL || currToken->type == STRING_LITERAL;
}

void Parser::deleteAST(structureArray ast) {
	for(auto el : ast) {
		delete el;
	}
}

void Parser::debugPrint(structureArray arr) {
	for (auto el : arr) {
		el->debugPrint(0);
	}
}
bool Parser::isEndBodyToken(tokenArray::iterator& currToken, std::vector<enum TokenType> v) {
	if (v.empty())
		return false;
	if (find(v.begin(), v.end(), currToken->type) != v.end())
		return true;
	else
		return false;
}
