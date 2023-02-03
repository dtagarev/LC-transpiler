#include <iostream>
/* #include <stdio.h> */
#include "Lexer/lexer.hpp"
#include "Parser/parser.hpp"
#include "Transformer/transformer.hpp"
#include "Generator/generator.hpp"

int main ()
{
	FILE *fh = fopen("LuaFiles/test3.lua", "r");
    if (!fh) { std::cerr << "Can't find file." << std::endl; }
    fseek(fh, 0, SEEK_END);
    size_t fileSize = ftell(fh);
    fseek(fh, 0, SEEK_SET);
	std::string fileContents(fileSize, ' ');
	fread(fileContents.data(), 1, fileSize, fh);
	fclose(fh);
	/* std::cout << fileContents << std::endl <<std:: endl; */
	/* std::cout << "-----------------------------------" << std::endl << std::endl; */
    Lexer lx;
	Parser ps;
	Transformer tr;	
	Generator gn;
	
	std::string testfile1 = "function fact (n) if n == 0 then  return 1  else  return n * fact(n-1)  end end local a = 1 local b = a*2 print(fact(b + 3)) ";
	
	std::string test2 = "globVar1 = 3; function f(n, m, l)  return 3 end function g(n,m,l) if n == m then return n + l else if m == l then return m + l else	return n + l + m end end end local a = 2; local c = 5; print(g(globVar1, a, c))";
	std::string testfile3 = "function g(n,m,l) if n == m then return n + l elseif m == l then return m + l else	return n + l + m end end local a = 2; local c = 5; print(g(globVar1, a, c))";
	std::vector<Token> tokens = lx.parse(fileContents);	
	
    /* for(Token currToken : tokens) { */
    /*     currToken.debugPrint(); */
    /* } */
	
	auto ast = ps.parse(tokens);
	
	/* ps.debugPrint(ast); */
	
	tr.transformAST(ast);
	
	/* tr.printInc(); */
	/* tr.printGlobalGeclarations(); */
	/* tr.printMainDeclarations(); */
	
	gn.generateCPPCode(tr.getIncludes() , tr.getGlobalDeclaration() , tr.getMainDeclaration());

	/* ps.deleteAST(ast); */
}

//to-do - test with lots of else if and while ( test if return in transformer is picked up inside else if and else
//get special functions to be generated inside C++ (like print)
//make transpliper that holds everything in main
//make for-structure
