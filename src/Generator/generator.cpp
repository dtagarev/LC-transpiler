#include "generator.hpp"
#include "generate-operation.hpp"

using structureArray = Generator::structureArray;
using includes = Generator::includes;	

void Generator::generateCPPCode(includes inc, structureArray globDeclarations, structureArray mainDeclarations) {
	/* std::ofstream f(fileName, std::ios::trunc); */
	
	/* if(!f.is_open()) { */
	/* 	throw std::runtime_error("Error generating new cpp file"); */
	/* } */
	
	for (auto el : inc) {
		//generateIncludes;
	}
	
	for(const auto& el : globDeclarations) {
		el->accept(&generateOperation);
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
