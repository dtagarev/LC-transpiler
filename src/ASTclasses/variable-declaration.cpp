#include "variable-declaration.hpp"
#include "structure.hpp"
#include "ast-visitor.h"

void VariableDeclaration::accept(AstVisitor* v) {
	v->visit(this);
}

void VariableDeclaration::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Variable_Declaration(" << returnType << ")(" << structureType << "): " << name << std::endl;
	std::cout << std::string(indent, '\t') << " Declaration: " << std::endl;
	for (auto el : declaration) {
			el->debugPrint(indent + 1);
	}
}
void VariableDeclaration::free() {
	
	for (auto el : declaration) {
		delete el;	
	}
}
 VariableDeclaration::VariableDeclaration() : Structure(VARIABLE_DECL) {}
 VariableDeclaration::~VariableDeclaration() {
	free();
}
