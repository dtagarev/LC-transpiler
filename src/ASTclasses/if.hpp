#ifndef IF_FILE
#define IF_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

struct If : Structure {
	using structureArray = Structure::structureArray;
	
	std::vector<structureArray> parameters;
	structureArray body;
	structureArray elseBody;

	void debugPrint(std::size_t indent) override;
	If();
};

#endif

