#include "function-declaration.hpp"
#include "structure.hpp"
#include "ast-visitor.h"

void FunctionDeclaration::accept(AstVisitor* v) {
	v->visit(this);
}

void FunctionDeclaration::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Function Declaration(" << returnType << ")(" << structureType << "): " << name << std::endl;
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

void FunctionDeclaration::free() {
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

FunctionDeclaration::FunctionDeclaration() : Structure(FUNC_DECL) {}

FunctionDeclaration::~FunctionDeclaration() {
	free();
}
