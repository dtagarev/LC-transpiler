#ifndef RETURN_STRUCTURE_FILE
#define RETURN_STRUCTURE_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

struct Return : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	structureArray toReturn;

	void debugPrint(std::size_t indent) override;
	Return();
};

#endif