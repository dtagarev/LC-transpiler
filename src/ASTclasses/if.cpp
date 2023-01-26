#include "if.hpp"

void If::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "IF: " << std::endl;
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
	for (auto el : elseBody) {
		el->debugPrint(indent + 1);	
	}
}

If::If() : Structure(IF_SCTRUCT) {}
