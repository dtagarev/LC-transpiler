#ifndef ELEMENT_STRUCTURE
#define ELEMENT_STRUCTURE

#include <iostream>
#include <string>
#include "structure.hpp"
#include "types.h"

enum ElementKind {
	NULKIND,
	OPERATOR,
	STR_LITERAL,
	NUM_LITERAL,
};

struct Element : Structure {
	enum ElementKind kind { NULKIND };
	enum Type returnType { NULLTYPE };
	std::string text;

	void debugPrint(std::size_t indent) override;
	Element();
};

#endif
