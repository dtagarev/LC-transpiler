#include "if.hpp"
#include "ast-visitor.h"

void If::accept(AstVisitor* v) {
	v->visit(this);
}

void If::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "IF(-)(" << structureType << "): " << std::endl;
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
	std::cout << std::string(indent, '\t') << "elseBody: " << std::endl;
	std::cout << std::string(indent, '\t') << " Parameters: " << std::endl;
	for (auto el : elseBody) {
		el->debugPrint(indent + 2);	
	}
}

void If::free() {
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
	
	for (auto el : elseBody) {
		delete el;	
	}
}
If::If() : Structure(IF_SCTRUCT) {}
If::~If() {
	free();
}
