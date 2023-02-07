#include <iostream>
#include "Lexer/lexer.hpp"
#include "Parser/parser.hpp"
#include "Transformer/transformer.hpp"
#include "Generator/generator.hpp"

int main ()
{
	/* FILE *fh = fopen("LuaFiles/test3.lua", "r"); */
    /* if (!fh) { std::cerr << "Can't find file." << std::endl; } */
    /* fseek(fh, 0, SEEK_END); */
    /* size_t fileSize = ftell(fh); */
    /* fseek(fh, 0, SEEK_SET); */
	/* std::string fileContents(fileSize, ' '); */
	/* fread(fileContents.data(), 1, fileSize, fh); */
	/* fclose(fh); */
	
	/* std::cout << fileContents << std::endl <<std:: endl; */
	
    Lexer lx;
	Parser ps;
	Transformer tr;	
	Generator gn;
	
	std::string fileContentsOrig = " globVar1 = 3; local function f(n, m, l) return 3 end function g(n,m,l) local var = 5; if n == m then return n + l elseif m == l then return m + l elseif m == 3 then return 3 end while var == 8 do var = var + 1; break; end	return var end local a = 2; local c = 5; print(g(globVar1, a, c))";
	/* std::string fileContents = "function g(n,m,l) local var = 5; if n == m then return n + l elseif m == l then return m + l elseif m == 3 then return 3 end while var == 8 do var = var + 1; end	return var end local a = 2; local c = 5; print(g(globVar1, a, c))"; */
	
	std::vector<Token> tokens = lx.parse(fileContentsOrig);	
	
    /* for(Token currToken : tokens) { */
    /*     currToken.debugPrint(); */
    /* } */
	
	/* std::cout << "-----------------------------------" << std::endl << std::endl; */
	auto ast = ps.parse(tokens);
	
	/* ps.debugPrint(ast); */
	/* std::cout << "-----------------------------------" << std::endl << std::endl; */
	
	tr.transformAST(ast);
	
	/* tr.printInc(); */
	/* tr.printGlobalGeclarations(); */
	/* tr.printMainDeclarations(); */
	
	gn.generateCPPCode(tr.getIncludes() , tr.getGlobalDeclaration() , tr.getMainDeclaration());

	ps.deleteAST(ast);
}

//add one line comments support
//make transpliper that holds everything in main
//make for-structure
