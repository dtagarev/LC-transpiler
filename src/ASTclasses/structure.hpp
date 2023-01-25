#ifndef STRUCTURE
#define STRUCTURE

#include <vector>

enum StructureType {
	UNKNOWN,
	ELEMENT,
	VARIABLE,
	FUNC_DECL,
	FUNC_CALL,
	RETURN_CALL,
};

class Structure {
public:
	using structureArray = std::vector<Structure*>;
	
	enum StructureType structureType { UNKNOWN };	
	
	virtual ~Structure() = default;
	/* virtual void debugPrint() = 0; */
};

#endif
