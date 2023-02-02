#ifndef TRANFORMER_FILE
#define TRANFORMER_FILE

#include <iostream>
#include <vector>
#include <string>
#include "../Lexer/lexer.hpp"
#include "../ASTclasses/structure.hpp"
#include "../ASTclasses/function-declaration.hpp"
#include "../ASTclasses/function-call.hpp"
#include "../ASTclasses/variable-declaration.hpp"
#include "../ASTclasses/variable-call.hpp"
#include "../ASTclasses/return.hpp"
#include "../ASTclasses/element.hpp"
#include "../ASTclasses/if.hpp"
#include "../ASTclasses/while.hpp"
#include "../ASTclasses/types.h"
#include "find-retrun-type-operation.hpp"

class Transformer {
	//to-do
	// determine all returnTypes - functions, variables, 
	// funcDeclaration, funcCall, VarDEcl, VarCall, if-else, retrunStruct
	public:
	using structureArray = Structure::structureArray;
	using includes = std::vector<std::string>;
	private:	
	
	includes inc;
	structureArray globalDeclarations; //only function declarations and global variables
	structureArray mainDeclaraions;
	
	FindRetrunTypeOp findRetrunType;
	
	void sortAst(structureArray ast);
	void detFDeclReturnType();
	
public:
	
	void transformAST(structureArray ast);
	
	const includes& getIncludes();
	const structureArray& getGlobalDeclaration();
	const structureArray& getMainDeclaration();
	
	void printInc();
	void printGlobalGeclarations();
	void printMainDeclarations();
};

#endif
