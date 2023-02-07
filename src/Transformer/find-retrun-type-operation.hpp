#ifndef FIND_RETURN_TYPE_OPERATION
#define FIND_RETURN_TYPE_OPERATION
#include "../ASTclasses/ast-visitor.h"
#include "../ASTclasses/structure.hpp"
#include "../ASTclasses/types.h"

class FindRetrunTypeOp : public AstVisitor {
public:
	using structureArray = Structure::structureArray;
private:
	Type determineTypeInsideBody(structureArray st);
public:	
	void visit(FunctionDeclaration*) override;
	void visit(FuncCall* ) override;
	void visit(VariableDeclaration* ) override;
	void visit(VariableCall* ) override;
	void visit(Return* ) override;
	void visit(Element*) override;
	void visit(If* ) override;
	void visit(While*) override;
	void visit(Break*) override;

};

#endif
