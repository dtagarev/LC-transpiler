#include "generate-operation.hpp"

void GenerateOp::visit(FunctionDeclaration* m) {
	
	std::cout << "FunctionDeclaration " << std::endl;
}
void GenerateOp::visit(FuncCall* m) {
	std::cout  << "FuncCall" << std::endl;
}
void GenerateOp::visit(VariableDeclaration*) {
	std::cout  << "VariableDeclaration" << std::endl;
}
void GenerateOp::visit(VariableCall*m ) {
	std::cout  << "VariableCall" << std::endl;
}
void GenerateOp::visit(Return* m) {
	std::cout  << "Return" << std::endl;
}
void GenerateOp::visit(Element* m) {
	std::cout  << "Element" << std::endl;
}
void GenerateOp::visit(If* m) {
	std::cout  << "If" << std::endl;
}
void GenerateOp::visit(While* m) {
	std::cout  << "While" << std::endl;
}

/* GenerateOp::GenerateOp(const char* fileName) { */
/* 	std::ofstream f(fileName); */
	
/* 	if(!f.is_open()) { */
/* 		throw std::runtime_error("Error creating new cpp file"); */
/* 	} */
/* 	f.close(); */
/* } */

/* GenerateOp::~GenerateOp() { */
/* 	f.close(); */
/* } */

/* std::ofstream GenerateOp::openFile(const char* fileName) { */
/* 	std::ofstream f(fileName, std::ios::app); */
	
/* 	if(!f.is_open()) { */
/* 		throw std::runtime_error("Error generating new cpp file"); */
/* 	} */
/* 	return f; */
/* } */
/* void GenerateOp::closeFile(std::ofstream& f) { */
/* 	f.close(); */
/* } */
