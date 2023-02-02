#include "element.hpp"
#include "ast-visitor.h"

void Element::accept(AstVisitor* v) {
	v->visit(this);
}

void Element::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Element(" << returnType << ")(" << structureType << "): " << text << std::endl;
}


Element::Element() : Structure(ELEMENT) {}

