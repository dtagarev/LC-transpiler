#ifndef TRANSPILER_FILE
#define TRANSPILER_FILE

#include <iostream>
#include "../Lexer/lexer.hpp"
#include "../Parser/parser.hpp"
#include "../Transformer/transformer.hpp"
#include "../Generator/generator.hpp"

class Transpiler {
    Lexer lx;
	Parser ps;
	Transformer tr;	
	Generator gn;
	
	void printTokens(std::vector<Token> tokens);
	void printAst(std::vector<Structure*>);
	void printTransformation();
public:
	void transpile(const char* filename);
};

#endif
