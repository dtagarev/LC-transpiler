#ifndef FUNCTION_DECLARATION_FILE
#define FUNCTION_DECLARATION_FILE

#include <iostream>
#include <string>
#include <vector>
#include "types.h"
#include "structure.hpp"

struct FunctionDeclaration : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	std::vector<structureArray> parameters;	
	structureArray body;

	enum Type functionType { VOID };
	bool local = false;
	void debugPrint(std::size_t indent) override;

	FunctionDeclaration();
};


#endif
