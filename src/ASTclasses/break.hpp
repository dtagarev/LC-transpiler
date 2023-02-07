#ifndef BREAK_STRUCTURE_FILE
#define BREAK_STRUCTURE_FILE

#include <iostream>
#include <string>
#include "structure.hpp"

class AstVisitor;

struct Break : Structure {
	
	Break();
	
	void debugPrint(std::size_t indent) override;
	
	void accept(AstVisitor*) override;		
	
};

#endif
