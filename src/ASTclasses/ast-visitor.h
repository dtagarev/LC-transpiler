#ifndef AST_VISITOR
#define AST_VISITOR

#include "../ASTclasses/function-declaration.hpp"
#include "../ASTclasses/function-call.hpp"
#include "../ASTclasses/variable-declaration.hpp"
#include "../ASTclasses/variable-call.hpp"
#include "../ASTclasses/return.hpp"
#include "../ASTclasses/element.hpp"
#include "../ASTclasses/if.hpp"
#include "../ASTclasses/while.hpp"

class AstVisitor {
public:
	
	virtual void visit(FunctionDeclaration*) = 0;
	virtual void visit(FuncCall* ) = 0;
	virtual void visit(VariableDeclaration* ) = 0;
	virtual void visit(VariableCall* ) = 0;
	virtual void visit(Return* ) = 0;
	virtual void visit(Element*) = 0;
	virtual void visit(If* ) = 0;
	virtual void visit(While*) = 0;
};

#endif
