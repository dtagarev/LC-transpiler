#include "generate-operation.hpp"
#include <stdexcept>

using structureArray = GenerateOp::structureArray;

const char* GenerateOp::getTypeInStr(Structure* el) {
	
	switch (el->returnType) {
		case DOUBLE: 
			return "double";
		case VOID:
			return "void";
		case STRING:
			throw std::runtime_error("Error inside generateType function, current type String not supported");
		default:
			throw std::runtime_error("Error, tried to generate invalid type");

	}
}
void GenerateOp::generateParameters(std::vector<structureArray> arr) {
		std::cout << '(';
	size_t length = arr.size();
	for (size_t i = 0; i < length-1; i++) {
		for (auto el : arr[i]) {
			el->accept(this);
		}
		std::cout << ',';
	}	
	for (auto el : arr[length - 1]) {
		el->accept(this);
	}
	std::cout << ')';
}

void GenerateOp::generateParametersFDecl(std::vector<structureArray> arr) {
	std::cout << '(';
	size_t length = arr.size();
	for (size_t i = 0; i < length-1; i++) {
		for (auto el : arr[i]) {
			if(el->reveal() == VARIABLE_CALL) {
				std::cout << "double ";
			}
			el->accept(this);
		}
		std::cout << ',';
	}	
	for (auto el : arr[length - 1]) {
		el->accept(this);
	}
	std::cout << ')';
}
void GenerateOp::generateDeclaration(structureArray arr) {
	for (auto el : arr) {
		el->accept(this);
	}
}
void GenerateOp::generateBody(structureArray arr) {
	for (auto el : arr) {
		el->accept(this);
		if(el->reveal() == FUNC_CALL)
			std::cout << ';' << std::endl;
	}
}

void GenerateOp::generateElseBody(structureArray arr) {
	std::cout << std::endl << "}\n";
	std::cout << "else ";
	if(arr[0]->reveal() == IF_SCTRUCT) {
		arr[0]->accept(this);
	}
	else {
		std::cout << "{\n";
		generateBody(arr);
	}
}

void GenerateOp::visit(FunctionDeclaration* m) {
	std::cout << getTypeInStr(m) << ' ' << m->name;
	generateParametersFDecl(m->parameters); 
	std::cout << " {" << std::endl;
	generateBody(m->body);
	std::cout  << std::endl << '}' << std::endl;
}
void GenerateOp::visit(FuncCall* m) {
	std::cout  << m->name << ' ';
	generateParameters(m->parameters);
}
void GenerateOp::visit(VariableDeclaration* m) {
	std::cout  << getTypeInStr(m) << ' ' << m->name  << " = ";
	generateDeclaration(m->declaration);
	std::cout << ';' << std::endl;
}
void GenerateOp::visit(VariableCall*m ) {
	std::cout  << m->name << ' ';
}
void GenerateOp::visit(Return* m) {
	std::cout  << "return ";
	generateDeclaration(m->toReturn);
	std::cout  << ";" << std::endl;
}
void GenerateOp::visit(Element* m) {
	std::cout  << m->text << ' ';
}
void GenerateOp::visit(If* m) {
	std::cout  << "if";
	generateParameters(m->parameters);
	std::cout  << '{' << std::endl;
	generateBody(m->body);
	if(!m->elseBody.empty()) {
		generateElseBody(m->elseBody);
	}
	std::cout  << std::endl << '}' << std::endl;

}
void GenerateOp::visit(While* m) {
	std::cout  << "while";
	generateParameters(m->parameters);
	std::cout  << "{" << std::endl;
	generateBody(m->body);
	std::cout << std::endl << "}" << std::endl;
}

