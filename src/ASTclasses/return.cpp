#include "return.hpp"

void Return::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Return(" << returnType << ")(" << structureType << "): " << std::endl;
	std::cout << std::string(indent, '\t') << " To return: " << std::endl;
	for (auto el : toReturn) {
		el->debugPrint(indent + 1);
	}
}

void Return::free() {
	for (auto el : toReturn) {
		delete el;	
	}
}
Return::Return() : Structure(RETURN_CALL) {}
Return::~Return() {
	free();
}
