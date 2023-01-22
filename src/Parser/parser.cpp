#include "parser.hpp"
#include <stdexcept>

using tokenArray = Parser::tokenArray;

void Parser::parse(tokenArray& tokens) {
	currToken = tokens.begin();
	endToken =tokens.end();
	
	while ( currToken != endToken ) {
	
	/* 	if(currToken->type == FUNCTION) { */
	/* 		if(expectFunction(currToken)) { */
	/* 		} */
	/* 		else { throw std::runtime_error("Invalid function declaration"); } */
	/* 	} */
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
}
std::optional<Statement>& Parser::expectFunction(tokenArray::iterator& currToken) {
	
	return nullopt;
}
