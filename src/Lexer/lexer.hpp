#ifndef LEXER
#define LEXER
#include <vector>
#include <string>
#include "tokens.hpp"

class Lexer {
public:
	using tokenArray = std::vector<Token>;
	
	tokenArray parse(const std::string& program);
private:
	void endToken(Token& token, tokenArray& arr);
	void reservedWordCheck(Token& token);	
};

#endif
