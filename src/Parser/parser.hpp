#ifndef PARSER
#define PARSER

#include <vector> 
#include <stack>
#include <string>
#include "../Lexer/lexer.hpp"
#include "../ASTclasses/structure.hpp"
#include "../ASTclasses/statement.hpp"
#include "../ASTclasses/function-declaration.hpp"


class Parser {
public:
	using tokenArray = Lexer::tokenArray;
	using structureArray = Structure::structureArray;
	using statementArray = Statement::statementArray;

private:
	
	tokenArray::iterator  currToken;
	tokenArray::iterator endToken;
	
	Statement parseFuncCall(tokenArray::iterator& currToken);
	Statement parseVariable(tokenArray::iterator& currToken);
	Statement parseOperator(tokenArray::iterator& currToken);
	Statement parseStrLiteral(tokenArray::iterator& currToken);
	Statement parseNumLiteral(tokenArray::iterator& currToken);
	Statement parseTable(tokenArray::iterator& currToken);
	
	Structure* expectFunction(tokenArray::iterator& currToken);
	statementArray expectParameters(tokenArray::iterator& currToken);
public:
	structureArray parse(tokenArray& tokens);
	void deleteAST();
private:

};

#endif
