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
	newFunc->body = parseBody(currToken);
	newFunc->returnType = determineFunctionReturnType(newFunc->body);
	return newFunc;
}
Structure* Parser::expectFunctionCall(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectVariableDeclaration(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectVariableCall(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectElem(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectTable(tokenArray::iterator& currToken) {
	return nullptr;
}
Structure* Parser::expectReturn(tokenArray::iterator& currToken) {
	return nullptr;
}

Structure* Parser::parseID(tokenArray::iterator& currToken) {
	std::string name = currToken->text;
	currToken++;
	if(currToken->type == L_PARENT) { //functionCall
		currToken--;
		return expectFunctionCall(currToken);
	} else if(currToken->type == L_BRACKET) { //table
		currToken--;
		return expectTable(currToken);
	} else if(currToken->type == ASSIGN) { //variable declaration
		currToken--;
		return expectVariableDeclaration(currToken);
	} else { //variable
		currToken--;
		return expectVariableCall(currToken);
	}
	throw std::runtime_error("Unknown identifier");
	//keywords?
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

