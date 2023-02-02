#ifndef GENERATOR_FILE
#define GENERATOR_FILE

#include <iostream>
#include "../ASTclasses/structure.hpp"
#include "../Transformer/transformer.hpp"
#include "generate-operation.hpp"
#include <fstream>

class Generator {
public:
	using structureArray = Structure::structureArray;
	using includes = Transformer::includes;	
	
private:
	void generateInsideBody(structureArray arr);
	GenerateOp generateOperation;
	/* std::ofstream openFile(const char* fileName); */	
	/* void closeFile(std::ofstream& f); */
public:	
	/* Generator(const char* filename); */
	
	void generateCPPCode(includes inc, structureArray globDeclarations, structureArray mainDeclarations);
};
#endif

