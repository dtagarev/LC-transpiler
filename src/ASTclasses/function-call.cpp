#include "function-call.hpp"

void FuncCall::debugPrint(std::size_t indent) {
	std::cout << std::string(indent, '\t') << "Function Call: " << std::endl;
	std::cout << std::string(indent, '\t') << " Parameters: " << std::endl;
	for (auto el : parameters) {
		for(auto ell : el) {
			ell->debugPrint(indent + 1);
		}
	}
}

FuncCall::FuncCall() : Structure(FUNC_CALL) {}
