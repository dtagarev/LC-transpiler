#include <iostream>
#include <stdio.h>
#include "Lexer/lexer.hpp"
#include "Parser/parser.hpp"


int main ()
{
	FILE *fh = fopen("LuaFiles/test2.lua", "r");
    if (!fh) { std::cerr << "Can't find file." << std::endl; }
    fseek(fh, 0, SEEK_END);
    size_t fileSize = ftell(fh);
    fseek(fh, 0, SEEK_SET);
	std::string fileContents(fileSize, ' ');
	fread(fileContents.data(), 1, fileSize, fh);
	
	/* std::cout << fileContents << std::endl <<std:: endl; */
	/* std::cout << "-----------------------------------" << std::endl << std::endl; */
	
    Lexer lx;
	Parser ps;
	std::string testfile1 = "function fact (n) if n == 0 then  return 1  else  return n * fact(n-1.5)  end end local a = 1 local b = a*2 print(fact(b + 3)) ";
	std::vector<Token> tokens = lx.parse(fileContents);	
	auto ast = ps.parse(tokens);
	
	ps.debugPrint(ast);
    /* for(Token currToken : tokens) { */
    /*     currToken.debugPrint(); */
    /* } */
	ps.deleteAST(ast);
}

//todo - create if-else construction, parse variable declaration ( need to determine functionCall returnType)
