#ifndef STATEMENT
#define STATEMENT

#include <vector>
#include <string>
#include "types.h"
#include "structure.hpp"

enum StatementKind {
	FUNCTION_CALL,
	VARIABLE_NAME,
	OPERATOR_CALL,
	TABLE_CALL,
	STR_LITERAL,
	NUM_LITERAL,
};

struct Statement : Structure {
	using statementArray = std::vector<Statement>;
	
	enum StatementKind kind { VARIABLE_NAME };
	enum Type statementType { VOID };
	std::string text;
	statementArray parameters;	
};

#endif
