#ifndef FUNC_CALL_FILE
#define FUNC_CALL_FILE

#include <iostream>
#include <vector>
#include <string>
#include "structure.hpp"
#include "types.h"

struct FuncCall : Structure {
	using structureArray = Structure::structureArray;
	
	enum Type returnType { NULLTYPE };
	std::string name;
	std::vector<structureArray> parameters;

	void debugPrint(std::size_t indent) override;
	FuncCall();
};

#endif
