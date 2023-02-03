#include "find-retrun-type-operation.hpp"

using structureArray = FindRetrunTypeOp::structureArray;

Type FindRetrunTypeOp::determineTypeInsideBody(structureArray st)  {
	Type toReturn = VOID;

	for (Structure* el : st) {
		if(el->reveal() == RETURN_CALL) {
			toReturn = DOUBLE;
		} 
		
		el->accept(this);
		
		if(el->reveal() == IF_SCTRUCT || el->reveal() == WHILE_STRUCT) {
			if(el->returnType != VOID) {
				toReturn = el->returnType;
			}
		}
	}
	return toReturn;
}
void FindRetrunTypeOp::visit(FunctionDeclaration* m) {
	m->returnType = determineTypeInsideBody(m->body);
}
void FindRetrunTypeOp::visit(FuncCall* m) {
	return;
}
void FindRetrunTypeOp::visit(VariableDeclaration* m) {
	m->returnType = DOUBLE;
}
void FindRetrunTypeOp::visit(VariableCall*m ) {
	m->returnType = DOUBLE;
}
void FindRetrunTypeOp::visit(Return* m) {
	return;
}
void FindRetrunTypeOp::visit(Element* m) {
	return;
}
void FindRetrunTypeOp::visit(If* m) {
	m->returnType = determineTypeInsideBody(m->body);
	if(m->returnType == VOID) {
		for (auto el : m->elseIfBody) {
			if(m->returnType == VOID) {
				m->returnType = determineTypeInsideBody(el);
			} else { 
				break; 
			}
		}
	}
	if(m->returnType == VOID) {	
		m->returnType = determineTypeInsideBody(m->body);
	}
}
void FindRetrunTypeOp::visit(While* m) {
	m->returnType = determineTypeInsideBody(m->body);
}
