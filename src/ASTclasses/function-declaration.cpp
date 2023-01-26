#include "function-declaration.hpp"
#include "structure.hpp"

void FunctionDeclaration::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Function: " << name << std::endl;
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
FunctionDeclaration::FunctionDeclaration() : Structure(FUNC_DECL) {}
