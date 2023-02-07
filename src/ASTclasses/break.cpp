#include "break.hpp"
#include "ast-visitor.h"

void Break::accept(AstVisitor* v) {
	v->visit(this);
}

void Break::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Break" << std::endl;
}

Break::Break() : Structure(BREAK_CALL) {}
