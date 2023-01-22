#ifndef PARSER
#define PARSER

#include <vector> 
#include <optional>
#include "../Lexer/lexer.hpp"
#include "../ASTclasses/statement.hpp"


class Parser {
public:
	using tokenArray = Lexer::tokenArray;
	using statementArray = Statement::statementArray;

private:
	
	tokenArray::iterator  currToken;
	tokenArray::iterator endToken;
	
	std::optional<Structure>& expectFunction(tokenArray::iterator& currToken);
public:
	void parse(tokenArray& tokens);
private:

};

#endif
