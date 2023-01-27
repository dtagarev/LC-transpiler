#ifndef STRUCTURE_FILE
#define STRUCTURE_FILE

#include <vector>
#include <iostream>
/* #include "elementKind.h" */

enum StructureType {
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
	
	enum StructureType structureType { UNKNOWN };	
	bool locality = false;
	
	Structure(StructureType type) : structureType(type) {}
	virtual ~Structure() = default;
	virtual void debugPrint(std::size_t indent) = 0;
	
	/* virtual void translateElement(enum ElementKind which, std::string to) = 0; */
	StructureType reveal() { return structureType; };
};

#endif
