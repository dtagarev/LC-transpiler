#ifndef IF_FILE
#define IF_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"
class AstVisitor;

struct If : Structure {
	using structureArray = Structure::structureArray;
	
private:	
	void free();	
public:	
	std::vector<structureArray> parameters;
	structureArray body;
	std::vector<std::vector<structureArray>> elseIfParameters;
	std::vector<structureArray> elseIfBody;
	
	structureArray elseBody;

	void debugPrint(std::size_t indent) override; //chech if correct
	If();
	
	If(const If&) = delete;
	const If& operator=(const If&) = delete;
	
	void accept(AstVisitor*) override;		
	
	~If();
};

#endif

