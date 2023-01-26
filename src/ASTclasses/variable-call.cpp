#include "variable-call.hpp"
#include "structure.hpp"



void VariableCall::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "VariableCall(" << returnType << ")(" << structureType << "): " << name << std::endl;
}

VariableCall::VariableCall() : Structure(VARIABLE_CALL) {}
