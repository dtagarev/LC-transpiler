#ifndef VARIABLE
#define VARIABLE

#include <string>
#include "structure.hpp"
#include "types.h"

struct Variable : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	structureArray declaration;
};

#endif
