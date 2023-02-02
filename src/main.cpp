#include <iostream>
/* #include <stdio.h> */
#include "Lexer/lexer.hpp"
#include "Parser/parser.hpp"
#include "Transformer/transformer.hpp"
#include "Generator/generator.hpp"

int main ()
{
	/* FILE *fh = fopen("LuaFiles/test1.lua", "r"); */
    /* if (!fh) { std::cerr << "Can't find file." << std::endl; } */
    /* fseek(fh, 0, SEEK_END); */
    /* size_t fileSize = ftell(fh); */
    /* fseek(fh, 0, SEEK_SET); */
	/* std::string fileContents(fileSize, ' '); */
	/* fread(fileContents.data(), 1, fileSize, fh); */
	/* fclose(fh); */
	/* std::cout << fileContents << std::endl <<std:: endl; */
	/* std::cout << "-----------------------------------" << std::endl << std::endl; */
    Lexer lx;
	Parser ps;
	Transformer tr;	
	Generator gn;
	
	std::string testfile1 = "function fact (n) if n == 0 then  return 1  else  return n * fact(n-1)  end end local a = 1 local b = a*2 print(fact(b + 3)) ";
	
	std::vector<Token> tokens = lx.parse(testfile1);	
	auto ast = ps.parse(tokens);
	
	/* ps.debugPrint(ast); */
    /* for(Token currToken : tokens) { */
        /* currToken.debugPrint(); */
    /* } */
	
	tr.transformAST(ast);
	
	/* tr.printInc(); */
	/* tr.printGlobalGeclarations(); */
	/* tr.printMainDeclarations(); */
	
	gn.generateCPPCode(tr.getIncludes() , tr.getGlobalDeclaration() , tr.getMainDeclaration());

	ps.deleteAST(ast);
}

//to-do - determine how to access structures data and where to generate code; in the astClasses or in the generator
// last time was defining functions inside Structures
