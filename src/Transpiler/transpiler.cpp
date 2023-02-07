#include "transpiler.hpp"

void Transpiler::printTokens(std::vector<Token> tokens) {
    for(Token currToken : tokens) {
        currToken.debugPrint();
    }
}

void Transpiler::printAst(std::vector<Structure*> ast) {
	ps.debugPrint(ast);
}

void Transpiler::printTransformation() {
	tr.printInc();
	tr.printGlobalGeclarations();
	tr.printMainDeclarations();
}

void Transpiler::transpile(const char* filename) {
	FILE *fh = fopen(filename, "r");
    if (!fh) { std::cerr << "Can't find file." << std::endl; }
    fseek(fh, 0, SEEK_END);
    size_t fileSize = ftell(fh);
    fseek(fh, 0, SEEK_SET);
	std::string fileContents(fileSize, ' ');
	fread(fileContents.data(), 1, fileSize, fh);
	fclose(fh);
	
	//for debugging
	std::string fileContentsOrig = " globVar1 = 3; local function f(n, m, l) return 3 end function g(n,m,l) local var = 5; if n == m then return n + l elseif m == l then return m + l elseif m == 3 then return 3 end while var == 8 do var = var + 1; break; end	return var end local a = 2; local c = 5; print(g(globVar1, a, c))";
	
	std::vector<Token> tokens = lx.parse(fileContents);	//lexer parsing tokens
	std::vector<Structure*> ast = ps.parse(tokens); // parser generating ast
	tr.transformAST(ast); //transformer making ast into intermediate model
	
	/* printTokens(tokens); */
	/* printAst(ast); */
	/* printTransformation(); */
	
	gn.generateCPPCode(tr.getIncludes() , tr.getGlobalDeclaration() , tr.getMainDeclaration()); // generator generating cpp code
	
	ps.deleteAST(ast);
}
