#ifndef STRUCTURE
#define STRUCTURE

#include <vector>

class Structure {
public:
	using structureArray = std::vector<Structure>;
	virtual ~Structure() = default;
	
	virtual void debugPrint() = 0;
};
#endif
