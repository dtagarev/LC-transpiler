#ifndef VARIABLE_CALL_FILE
#define VARIABLE_CALL_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

struct VariableCall : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	
	void debugPrint(std::size_t indent) override;
	VariableCall();
};

#endif
