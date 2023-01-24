#include "parser.hpp"
#include <stdexcept>

using tokenArray = Parser::tokenArray;
using structureArray = Parser::structureArray;
using statementArray = Parser::statementArray;

structureArray Parser::parse(tokenArray& tokens) {
	currToken = tokens.begin();
	endToken =tokens.end();
	
	while ( currToken != endToken ) {
	
		if(currToken->type == FUNCTION) {
			if(!expectFunction(currToken)) {
				throw std::runtime_error("Invalid function declaration");
			}
		}
	/* 	if(currToken->type == IDENTIFIER){ */ 
	/* 		if(expectVariableDeclaration()) { */
	/* 		} else if (expectFunctionCall()) { */
	/* 		} else { */
	/* 			throw std::runtime_error("Invalid Identifier "); */ 
	/* 		} */
			
		/* 	if(expectExpression()) */
		/* 		continue; */

		/* 	throw std::runtime_error("Unhandled identifier on line "); */
		/* } */
		/* if(currToken->type == FUNCTION) { */
		/* 	expectFunction(currToken); */
		/* } */
	
	}
	return std::vector<Structure*>();
}
Structure* Parser::expectFunction(tokenArray::iterator& currToken) {
	FunctionDeclaration* func = new FunctionDeclaration();
	currToken++;
	if(currToken->type == IDENTIFIER) {
		func->name = currToken->text;
		currToken++;
	}
	else {
		delete func;
		return nullptr;
	}
	/* while(currToken->type != L_PARENT) */
	/* 	currToken++; */
	func->parameters = expectParameters(currToken);

	return nullptr;
}
statementArray Parser::expectParameters(tokenArray::iterator& currToken) {
	statementArray arr;
	std::stack<char> bracketCheck;
	bracketCheck.push('(');

	while(!bracketCheck.empty()) {
		if(currToken->type == COMMA)
			continue;
		
		if(currToken->type == L_PARENT ||currToken->type == L_BRACKET ||currToken->type == L_BRACE) {
			bracketCheck.push('(');
		}
		if(currToken->type == R_PARENT ||currToken->type == R_BRACKET ||currToken->type == R_BRACE) {
			bracketCheck.pop();
		}
		
		Statement tmp;
		if(currToken->type == STRING_LITERAL) {
			tmp.kind = STR_LITERAL;
			tmp.text = currToken->text;
			arr.push_back(tmp);
		} else if(currToken->type == NUMBER_LITERAL ) {
			tmp.kind = NUM_LITERAL;
			tmp.text = currToken->text;
			arr.push_back(tmp);
		} else if(currToken->type == IDENTIFIER) {
			tmp.kind = VARIABLE_NAME;
			tmp.text = currToken->text;
			arr.push_back(tmp);
		} else if (
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
				currToken->type == PIPE ) {

			tmp.kind = OPERATOR_CALL;
			tmp.text = currToken->text;
			arr.push_back(tmp);
		}
		currToken++;
	}
	return arr;
}
	
Statement Parser::parseFuncCall(tokenArray::iterator& currToken) {
	Statement tmp;
	tmp.
}
Statement Parser::parseVariable(tokenArray::iterator& currToken);
Statement Parser::parseOperator(tokenArray::iterator& currToken);
Statement Parser::parseStrLiteral(tokenArray::iterator& currToken);
Statement Parser::parseNumLiteral(tokenArray::iterator& currToken);
Statement Parser::parseTable(tokenArray::iterator& currToken);
