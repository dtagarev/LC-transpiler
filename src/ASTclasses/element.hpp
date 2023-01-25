#ifndef ELEMENT
#define ELEMENT

#include <string>
#include "structure.hpp"

enum ElementKind {
	NULKIND,
	OPERATOR,
	STR_LITERAL,
	NUM_LITERAL,
};

struct Element : Structure {
	enum ElementKind kind { NULKIND };
	std::string text;

	/* void debugPrint() override; */
};

#endif
