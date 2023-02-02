#ifndef WHILE_FILE
#define WHILE_FILE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"
class AstVisitor;

struct While : Structure {
	using structureArray = Structure::structureArray;
	
private:	
	void free();	
public:	
	std::vector<structureArray> parameters;
	structureArray body;
	
	void debugPrint(std::size_t indent) override;
	
	While();
	While(const While&) = delete;
	const While& operator=(const While&) = delete;
	
	void accept(AstVisitor*) override;		
	
	~While();
};

#endif
