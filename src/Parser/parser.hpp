#ifndef PARSER
#define PARSER

#include <vector> 
#include <string>
#include <unordered_map>
#include "../Lexer/lexer.hpp"
#include "../ASTclasses/structure.hpp"
#include "../ASTclasses/function-declaration.hpp"
#include "../ASTclasses/types.h"


class Parser {
public:
	using tokenArray = Lexer::tokenArray;
	using structureArray = Structure::structureArray;

private:
	std::unordered_map< std::string , enum Type> functionTypes;
	tokenArray::iterator  currToken;
	tokenArray::iterator endToken;
	
	Structure* expectFunctionDeclaration(tokenArray::iterator& currToken);
	Structure* expectFunctionCall(tokenArray::iterator& currToken);
	Structure* expectVariableDeclaration(tokenArray::iterator& currToken);
	Structure* expectVariableCall(tokenArray::iterator& currToken);
	Structure* expectElem(tokenArray::iterator& currToken);
	//to-be continued...
	Structure* expectTable(tokenArray::iterator& currToken);
	Structure* expectReturn(tokenArray::iterator& currToken);
	
	Structure* parseID(tokenArray::iterator& currToken);
	std::vector<structureArray> parseParameters(tokenArray::iterator& currToken);
	structureArray parseBody(tokenArray::iterator& currToken);
	
	enum Type determineFunctionReturnType(structureArray body);
	bool isOperator(tokenArray::iterator& currToken);
	bool isLiteral();
	
public:
	structureArray parse(tokenArray& tokens);
	void deleteAST(structureArray ast);
};

#endif
