#ifndef STRUCTURE_FILE
#define STRUCTURE_FILE

#include <vector>
#include <iostream>
#include "types.h"
class AstVisitor;

enum StructureKind {
	UNKNOWN, 
	VARIABLE_DECL,
	VARIABLE_CALL,
	FUNC_DECL,
	FUNC_CALL,
	RETURN_CALL,
	TABLE_DECL, //to-do
	ELEMENT, 
	IF_SCTRUCT,
	WHILE_STRUCT,
};

class Structure {
public:
	using structureArray = std::vector<Structure*>;
	
	enum StructureKind structureType { UNKNOWN };	
	enum Type returnType { NULLTYPE };
	bool locality = false;
	
	
	Structure(StructureKind type) : structureType(type) {}
	virtual ~Structure() = default;
	virtual void debugPrint(std::size_t indent) = 0;
	
	virtual void accept(class AstVisitor*) = 0;
	
	StructureKind reveal() { return structureType; };
};

#endif
