#ifndef VARIABLE_DECLARATION_FILE
#define VARIABLE_DECLARATION_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

struct VariableDeclaration : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	structureArray declaration;
	
	void debugPrint(std::size_t indent) override;

	VariableDeclaration();
};

#endif