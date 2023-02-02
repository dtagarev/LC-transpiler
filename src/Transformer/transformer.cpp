#include "transformer.hpp"

using structureArray = Transformer::structureArray;
using includes = Transformer::includes;

const includes& Transformer::getIncludes() {
	return inc;
}

const structureArray& Transformer::getGlobalDeclaration() {
	return globalDeclarations;
}
const structureArray& Transformer::getMainDeclaration() {
	return mainDeclaraions;
}

void Transformer::transformAST(structureArray ast) {
	sortAst(ast);
	detFDeclReturnType();
	detVDeclReturnType();
	inc.push_back("#include <iostream>");
}


void Transformer::sortAst(structureArray ast) {
	for(auto el : ast) {
		//must find includes
		
		if(el->reveal() == FUNC_DECL) {
			globalDeclarations.push_back(el);
		} else if(!el->locality) {
			globalDeclarations.push_back(el);
		} else {
			mainDeclaraions.push_back(el);
		}
	}
}

void Transformer::detFDeclReturnType() {
	for (auto el : globalDeclarations) {
		if(el->reveal() == FUNC_DECL)
			el->accept(&findRetrunType);
	}
}

void Transformer::detVDeclReturnType() {
	for (auto el : globalDeclarations) {
		if(el->reveal() == VARIABLE_DECL)
			el->accept(&findRetrunType);
	}

	for (auto el : mainDeclaraions) {
		if(el->reveal() == VARIABLE_DECL)
			el->accept(&findRetrunType);
	}
	
}

void Transformer::printInc() {
	std::cout << "______ Inlcudes _______" << std::endl;
	std::cout << std::endl;
	for (auto el : inc) {
		std::cout << el << ' ';	
	}
	std::cout << std::endl;
}

void Transformer::printGlobalGeclarations() {
	std::cout << "______ Global Declarations _______" << std::endl;
	std::cout << std::endl;
	for (auto el : globalDeclarations) {
		el->debugPrint(0);
	}
	std::cout << std::endl;
}

void Transformer::printMainDeclarations() {
	std::cout << "______ Main Declarations _______" << std::endl;
	std::cout << std::endl;
	for (auto el : mainDeclaraions) {
		el->debugPrint(0);
	}
	std::cout << std::endl;
}
