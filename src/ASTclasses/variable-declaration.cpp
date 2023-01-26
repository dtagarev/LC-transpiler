#include "variable-declaration.hpp"
#include "structure.hpp"

void VariableDeclaration::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Variable_Declaration: " << name << std::endl;
	std::cout << std::string(indent, '\t') << " Declaration: " << name << std::endl;
	for (auto el : declaration) {
			el->debugPrint(indent + 1);
	}
}
 VariableDeclaration::VariableDeclaration() : Structure(VARIABLE_DECL) {}
