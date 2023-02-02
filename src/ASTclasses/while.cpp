#include "while.hpp"
#include "ast-visitor.h"

void While::accept(AstVisitor* v) {
	v->visit(this);
}

void While::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "While(-)(" << structureType << "): " << std::endl;
	std::cout << std::string(indent, '\t') << " Parameters: " << std::endl;
	for (auto el : parameters) {
		for( auto ell : el) {
			ell->debugPrint(indent + 1);	
		}
	}
	std::cout << std::string(indent, '\t') << "Body: " << std::endl;
	for (auto el : body) {
		el->debugPrint(indent + 1);	
	}
}

void While::free() {
	size_t length = parameters.size();
	for (size_t i = 0; i < length; i++) {
		size_t length2 = parameters[i].size();
		for (size_t j = 0; j < length2; j++) {
			delete parameters[i][j];
		}
	}
	
	for (auto el : body) {
		delete el;	
	}
}

While::While() : Structure(WHILE_STRUCT) {}
While::~While() {
	free();
}
