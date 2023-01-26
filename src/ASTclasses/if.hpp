#ifndef IF_FILE
#define IF_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

struct If : Structure {
	using structureArray = Structure::structureArray;
	
private:	
	void free();	
public:	
	std::vector<structureArray> parameters;
	structureArray body;
	structureArray elseBody;

	void debugPrint(std::size_t indent) override;
	If();
	
	If(const If&) = delete;
	const If& operator=(const If&) = delete;
	~If();
};

#endif

