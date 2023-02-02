#ifndef GENERATE_OPERATION
#define GENERATE_OPERATION

#include <iostream>
#include <fstream>
#include "../ASTclasses/ast-visitor.h"

class GenerateOp : public AstVisitor {
	
	/* std::ofstream openFile(const char* fileName); */	
	/* void closeFile(std::ofstream& f); */
	/* std::ofstream f; */	
public:	
	/* GenerateOp(const char* filename); */
	
	void visit(FunctionDeclaration*) override;
	void visit(FuncCall* ) override;
	void visit(VariableDeclaration* ) override;
	void visit(VariableCall* ) override;
	void visit(Return* ) override;
	void visit(Element*) override;
	void visit(If* ) override;
	void visit(While*) override;

	/* ~GenerateOp(); */
};

#endif
