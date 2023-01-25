#include <iostream>
#include <stdio.h>
#include "Lexer/lexer.hpp"
#include "Parser/parser.hpp"

int main ()
{
	FILE *fh = fopen("LuaFiles/test1.lua", "r");
    if (!fh) { std::cerr << "Can't find file." << std::endl; }
    fseek(fh, 0, SEEK_END);
    size_t fileSize = ftell(fh);
    fseek(fh, 0, SEEK_SET);
	std::string fileContents(fileSize, ' ');
    fread(fileContents.data(), 1, fileSize, fh);
	/* std::cout << fileContents << std::endl <<std:: endl; */
	std::cout << "-----------------------------------" << std::endl << std::endl;
    Lexer lx;
	Parser ps;
	std::vector<Token> tokens = lx.parse(fileContents);	
	/* ps.parse(tokens); */
    for(Token currToken : tokens) {
        currToken.debugPrint();
    }

}

//todo - parseParamater function 
