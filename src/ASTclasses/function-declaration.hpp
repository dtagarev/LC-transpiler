#ifndef FUNCTION_DECLARATION_FILE
#define FUNCTION_DECLARATION_FILE

#include <iostream>
#include <string>
#include <vector>
#include "types.h"
#include "structure.hpp"
class AstVisitor;

struct FunctionDeclaration : Structure {
	using structureArray = Structure::structureArray;
	
private:	
	void free();	
public:	
	
	/* enum Type returnType { NULLTYPE }; */
	std::string name;
	std::vector<structureArray> parameters;	
	structureArray body;

	bool local = false;
	void debugPrint(std::size_t indent) override;

	FunctionDeclaration();
	FunctionDeclaration(const FunctionDeclaration&) = delete;
	const FunctionDeclaration& operator=(const FunctionDeclaration&) = delete;
	
	void accept(AstVisitor*) override;	
	
	~FunctionDeclaration();
};


#endif
