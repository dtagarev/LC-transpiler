#include "variable-call.hpp"
#include "structure.hpp"
#include "ast-visitor.h"

void VariableCall::accept(AstVisitor* v) {
	v->visit(this);
}



void VariableCall::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "VariableCall(" << returnType << ")(" << structureType << "): " << name << std::endl;
}

VariableCall::VariableCall() : Structure(VARIABLE_CALL) {}
