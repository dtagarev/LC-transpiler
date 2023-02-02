#include "parser.hpp"
#include <stdexcept>

using tokenArray = Parser::tokenArray;
using structureArray = Parser::structureArray;

structureArray Parser::parse(tokenArray& tokens) {
	currToken = tokens.begin();
	endToken =tokens.end();
	structureArray res;
	while (currToken != endToken && currToken->type != EOF_TOKEN) { //must parse - elem?, funcDecl, funcCall, varDecl, varCall, tableDecl, tableCall, if-else , while
		bool local = false;
		if (currToken->type == LOCAL) {
			local = true;
			currToken++;
		}
		
		if(currToken->type == FUNCTION) {
			Structure* curr = expectFunctionDeclaration(currToken);
			curr->locality = local;
			res.push_back(curr);

		} else if (currToken->type == IDENTIFIER ){ //covers - VariableCall, FuncCall, VariableDeclaration, tableCall, tableDecl
			Structure* curr = parseID(currToken); //currToken moved inide function
			if(curr->reveal() == FUNC_CALL) {
				curr->locality = true;
			} else
				curr->locality = local;
			
			res.push_back(curr);

		} else if (currToken->type ==  IF){
			Structure* curr = expectIf(currToken); //currToken moved inide function
			curr->locality = true;
			res.push_back(curr); 
		} else if (currToken->type ==  WHILE){
			Structure* curr = expectWhile(currToken); //currToken moved inide function
			curr->locality = true;
			res.push_back(curr); 
		}else {
			std::cout << currToken->text << std::endl;
			throw std::runtime_error("Unhandled element inside program's body");
		}
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
	
	std::vector<enum TokenType> endParam;
	newFunc->parameters = parseParameters(currToken);

	std::vector<enum TokenType> endBody;
	endBody.push_back(END);
	
	newFunc->body = parseBody(currToken, endBody);
	/* newFunc->returnType = determineFunctionReturnType(newFunc->body); */
	return newFunc;
}
Structure* Parser::expectFunctionCall(tokenArray::iterator& currToken) {
	if(currToken->type != IDENTIFIER) {
		throw std::runtime_error("Unknown functionCall name");
	}
	FuncCall* fCall = new FuncCall();
	fCall->name = currToken->text;
	currToken++; // moves token to L_PARENT
	/* std::vector<enum TokenType> endParam; */
	/* endParam.push_back(R_PARENT); */
	fCall->parameters = parseParameters(currToken);
	return fCall;
}
Structure* Parser::expectVariableDeclaration(tokenArray::iterator& currToken) {
	if(currToken->type != IDENTIFIER)
		throw std::runtime_error("Unexpected token at variable declaration");
	VariableDeclaration* newVar = new VariableDeclaration();
	newVar->name = currToken->text;
	currToken++; // move to ASSIGN
	newVar->declaration = parseDeclaration(currToken);
	return newVar;
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
Structure* Parser::expectIf(tokenArray::iterator& currToken) {
	If* newIf = new If();
	std::vector<enum TokenType> endParam;
	endParam.push_back(THEN);
	currToken++; //skips the if token
	newIf->parameters = parseParameters(currToken, endParam);
	std::vector<enum TokenType> endBody;
	endBody.push_back(END);
	endBody.push_back(ELSE);
	newIf->body = parseBody(currToken, endBody);
	currToken--;
	if (currToken->type == ELSE) {
		currToken++;
		newIf ->elseBody = parseBody(currToken, endBody);
	}
	return newIf;
}

Structure* Parser::expectWhile(tokenArray::iterator& currToken) {
	While* newWhile = new While();
	std::vector<enum TokenType> endParam;
	endParam.push_back(DO);
	currToken++; //skips the while token
	newWhile->parameters = parseParameters(currToken, endParam);
	std::vector<enum TokenType> endBody;
	endBody.push_back(END);
	newWhile->body = parseBody(currToken, endBody);
	return newWhile;
}
Structure* Parser::expectTable(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectReturn(tokenArray::iterator& currToken) {
	Return* newReturn = new Return();
	if(currToken->type != RETURN)
		throw std::runtime_error("Invalid token. Token must be return");
	currToken++;
	newReturn->toReturn = parseDeclaration(currToken);
	return newReturn;
}

std::vector<structureArray> Parser::parseParameters(tokenArray::iterator& currToken, std::vector<enum TokenType> endBody) {
	std::vector<structureArray> arr;
	structureArray curr; 
	std::stack<char> parenCheck;
	bool parenCheckBool = true;

	if(currToken->type == L_PARENT) {
		parenCheck.push('(');	
		currToken++;
	}
	
	while (!isEndBodyToken(currToken, endBody) && parenCheckBool && currToken->type != EOF_TOKEN) {
		if(currToken->type == COMMA) {
			arr.push_back(curr);
			curr.clear();

		} else if(currToken->type == IDENTIFIER) {
			curr.push_back(parseID(currToken)); //currToken moved inside

		}else if(currToken->type == L_PARENT || currToken->type == L_BRACE || currToken->type == L_BRACKET) {
			parenCheck.push('(');
			curr.push_back(expectElem(currToken)); //currToken moved inside

		}else if(currToken->type == R_PARENT || currToken->type == R_BRACE || currToken->type == R_BRACKET) {
			parenCheck.pop();
			parenCheckBool = !parenCheck.empty();
			if(!parenCheck.empty())
				curr.push_back(expectElem(currToken)); //currToken moved inside

		} else if(isOperator(currToken) || isLiteral(currToken)) {
			curr.push_back(expectElem(currToken)); //currToken moved inside
			
		} else {
			std::cout << currToken->text << "|" << std::endl;
			throw std::runtime_error("Unhandled case inside parameters");
		}
	}
	//is changing this with the other a problem?
	if(currToken->type == R_PARENT) {
		currToken++;
	}
	if (isEndBodyToken(currToken, endBody)) {
		currToken++;
	}
	/* while (isEndBodyToken(currToken, endBody)) { */
	/* 	currToken++; */
	/* } */

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

	} else if(currToken->type == ASSIGN) { //variable declaration or table declaration
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
		} else if(currToken->type == IF) { 
			Structure* newIf = expectIf(currToken);
			body.push_back(newIf);

		} else if(currToken->type == RETURN) { // to-do -> elem?, while
			Structure* newReturn = expectReturn(currToken);
			body.push_back(newReturn);
			
		} else if(currToken->type == LOCAL) { 
			currToken++;
		} else {
			throw std::runtime_error("Invalid structure inside body");
			/* currToken++; */
		}
	}
	if (isEndBodyToken(currToken, endBody)) {
		currToken++;
	}
	return body;
}


structureArray Parser::parseDeclaration(tokenArray::iterator& currToken) {
	structureArray declArray;
	bool mustBeOperator = false;

	if(currToken->type == ASSIGN)
		currToken++;

	// can be identifier/literal or OPERATOR in repeating sequence. if the sequence is brocken the declaration is finished
	while(true) {
		if(mustBeOperator && !isOperator(currToken))  {
			break;
		} else if(!mustBeOperator && isOperator(currToken)) {
			break;
		}
		
		if (currToken->type == IDENTIFIER) {
			declArray.push_back(parseID(currToken)); //moves currToken to next token
			mustBeOperator = true;
		} else if(isLiteral(currToken)) {
			declArray.push_back(expectElem(currToken)); //moves currToken to next token
			mustBeOperator = true;
		} else if(isOperator(currToken)) {
			declArray.push_back(expectElem(currToken)); //moves currToken to next token
			mustBeOperator = false;
		}
	}
	return declArray;
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
