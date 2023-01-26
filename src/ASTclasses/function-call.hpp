#ifndef FUNC_CALL_FILE
#define FUNC_CALL_FILE

#include <iostream>
#include <vector>
#include <string>
#include "structure.hpp"
#include "types.h"

struct FuncCall : Structure {
	using structureArray = Structure::structureArray;
private:	
	void free();	
public:	
	enum Type returnType { NULLTYPE };
	std::string name;
	std::vector<structureArray> parameters;
	
	void debugPrint(std::size_t indent) override;
	FuncCall();
	FuncCall(const FuncCall&) = delete;
	const FuncCall& operator=(const FuncCall&) = delete;
	~FuncCall();
};

#endif
