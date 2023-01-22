#ifndef FUNCTION_DECLARATION
#define FUNCTION_DECLARATION

#include <string>
#include "statement.hpp"
#include "types.h"
#include "structure.hpp"

struct FunctionDeclaration : Structure {
	using statementArray = Statement::statementArray;
	using structureArray = Structure::structureArray;
	
	std::string name;
	statementArray parameters;	
	structureArray body;

	enum Type statementType { VOID };
	bool local = false;
};

#endif
