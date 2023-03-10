#ifndef GENERATE_OPERATION
#define GENERATE_OPERATION

#include <iostream>
#include <fstream>
#include <vector>
#include "../ASTclasses/ast-visitor.h"
#include"../ASTclasses/structure.hpp"

class GenerateOp : public AstVisitor {
public:
	using structureArray = Structure::structureArray;
private:
	
	const char* getTypeInStr(Structure* el);
	void generateParametersFDecl(std::vector<structureArray> arr);
	void generateParameters(std::vector<structureArray>);
	void generateDeclaration(structureArray);
	void generateBody(structureArray);
	void generateElseBody(structureArray);
	void generateElseIf(std::vector<structureArray> parameters, structureArray body);
	
	bool generateSpecialFunctionCall(FuncCall* );
	void generateSpecialFuncionParameters(std::vector<structureArray>);
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
