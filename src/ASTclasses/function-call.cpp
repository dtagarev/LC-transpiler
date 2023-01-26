#include "function-call.hpp"
#include <cstddef>

void FuncCall::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Function Call(" << returnType << ")(" << structureType << "): " << name << std::endl;
	std::cout << std::string(indent, '\t') << " Parameters: " << std::endl;
	for (auto el : parameters) {
		for(auto ell : el) {
			ell->debugPrint(indent + 1);
		}
	}
}

FuncCall::FuncCall() : Structure(FUNC_CALL) {}

void FuncCall::free() {
	size_t length = parameters.size();
	for (size_t i = 0; i < length; i++) {
		size_t length2 = parameters[i].size();
		for (size_t j = 0; j < length2; j++) {
			delete parameters[i][j];
		}
	}
}

FuncCall::~FuncCall() { 
	free(); 
};
