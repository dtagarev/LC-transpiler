#ifndef FUNC_CALL
#define FUNC_CALL

#include "structure.hpp"
#include <vector>
#include <string>
#include "types.h"

struct FuncCall : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	std::vector<structureArray> parameters;
};

#endif
