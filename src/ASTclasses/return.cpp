#include "return.hpp"

void Return::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Return: " << std::endl;
	for (auto el : toReturn) {
		el->debugPrint(indent + 1);
	}
}

Return::Return() : Structure(RETURN_CALL) {}
