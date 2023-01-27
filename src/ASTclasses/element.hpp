#ifndef ELEMENT_STRUCTURE
#define ELEMENT_STRUCTURE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"
#include "elementKind.h"


struct Element : Structure {
	enum ElementKind kind { NULKIND };
	enum Type returnType { NULLTYPE };
	std::string text;

	void debugPrint(std::size_t indent) override;
	Element();
};

#endif
