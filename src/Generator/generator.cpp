#include "generator.hpp"
#include "generate-operation.hpp"

using structureArray = Generator::structureArray;
using includes = Generator::includes;	

void Generator::generateCPPCode(includes inc, structureArray globDeclarations, structureArray mainDeclarations) {
	
	for (auto el : inc) {
		std::cout << el << std::endl;
	}
	
	/* for(const auto& el : globDeclarations) { */
	/* 	el->accept(&generateOperation); */
	/* } */
	
	generateInsideBody(globDeclarations);
	std::cout << "int main() {\n";
	/* for(const auto& el : mainDeclarations) { */
	/* 	el->accept(&generateOperation); */
	/* } */
	generateInsideBody(mainDeclarations);
	std::cout << std::endl;
	std::cout << "}" << std::endl;
}

void Generator::generateInsideBody(structureArray arr) {
	for(const auto& el : arr) {
		el->accept(&generateOperation);
		if(el->reveal() == FUNC_CALL) {
			std::cout << ";\n";
		}
	}
}

/* Generator::Generator(const char* filename) : generateOperation(filename){} */

/* std::ofstream Generator::openFile(const char* fileName) { */
/* 	std::ofstream f(fileName, std::ios::app); */
	
/* 	if(!f.is_open()) { */
/* 		throw std::runtime_error("Error generating new cpp file"); */
/* 	} */
/* 	return f; */
/* } */
/* void Generator::closeFile(std::ofstream& f) { */
/* 	f.close(); */
/* } */
