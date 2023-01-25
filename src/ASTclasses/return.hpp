#ifndef RETURN_STRUCTURE
#define RETURN_STRUCTURE

#include <string>
#include "structure.hpp"
#include "types.h"

struct Return : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	structureArray toReturn;
};

#endif
