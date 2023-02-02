#include "find-retrun-type-operation.hpp"

using structureArray = FindRetrunTypeOp::structureArray;

Type FindRetrunTypeOp::determineTypeInsideBody(structureArray st)  {
	Type toReturn = NULLTYPE;

	for (Structure* el : st) {
		if(el->reveal() == RETURN_CALL) {
			return DOUBLE;
		} else if(el->reveal() == IF_SCTRUCT || el->reveal() == WHILE_STRUCT) {
			el->accept(this);
			toReturn = el->returnType;
		}
	}
	return toReturn;
}
void FindRetrunTypeOp::visit(FunctionDeclaration* m) {
	return;
}
void FindRetrunTypeOp::visit(FuncCall* m) {
	return;
}
void FindRetrunTypeOp::visit(VariableDeclaration* m) {
	m->returnType = DOUBLE;
}
void FindRetrunTypeOp::visit(VariableCall*m ) {
	return;
}
void FindRetrunTypeOp::visit(Return* m) {
	return;
}
void FindRetrunTypeOp::visit(Element* m) {
	return;
}
void FindRetrunTypeOp::visit(If* m) {
	m->returnType = determineTypeInsideBody(m->body);
}
void FindRetrunTypeOp::visit(While* m) {
	m->returnType = determineTypeInsideBody(m->body);
}
