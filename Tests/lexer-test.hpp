#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include "doctest.h"
#include "../src/Lexer/lexer.hpp"
using namespace std;

TEST_SUITE("Lexer") {
	TEST_CASE("lexer-operators") {
		Lexer lx;
		std::string allOperators = "( ) { } [ ] + - * % ^ # = == <= >= ~= < << > >> / // ~ : :: ; , . .. ... & | ";
		std::vector<Token> tmp = lx.parse(allOperators);
		std::vector<TokenType> res;
		
		for (auto el : tmp) {
			res.push_back(el.type);
		}
		
		std::vector<TokenType> correcrAnswer = {
			L_PARENT,// WHITESPACE,
			R_PARENT,//WHITESPACE, 
			L_BRACE,//WHITESPACE,
			R_BRACE,//WHITESPACE,
			L_BRACKET,//WHITESPACE, 
			R_BRACKET,//WHITESPACE, 
			PLUS,//WHITESPACE, 
			MINUS,//	WHITESPACE,
			STAR,// WHITESPACE,
			PERCENT,// WHITESPACE,
			EXP, //WHITESPACE,
			SH, //WHITESPACE,
			ASSIGN,//WHITESPACE,
			EQUAL,//WHITESPACE,
			LESS_OR_EQUAL,//WHITESPACE,
			GREATER_OR_EQUAL,//WHITESPACE,
			NOT_EQUAL,//WHITESPACE,
			LESS_THAN,//WHITESPACE,
			DOUBLE_LESS_THAN,//WHITESPACE,
			GREATER_THAN,//WHITESPACE,
			DOUBLE_GREATER_THAN,//WHITESPACE,
			SLASH, //WHITESPACE,
			DOUBLE_SLASH, //WHITESPACE,
			TILDE, //WHITESPACE,
			COLON, //WHITESPACE,
			DOUBLE_COLON,//WHITESPACE,
			SEMI_COLON, //WHITESPACE,
			COMMA, //WHITESPACE,
			DOT, //WHITESPACE,
			DOUBLE_DOT,//WHITESPACE,
			ELLIPSIS, //WHITESPACE,
			AMPERSAND,//WHITESPACE, 
			PIPE, }; //WHITESPACE};
		CHECK_EQ(res, correcrAnswer);
	}
	TEST_CASE("lexer-recognises-number") {
		Lexer lx;
		std::string testProgram = "1234 ";
		std::vector<Token> tmp = lx.parse(testProgram);
		CHECK_EQ(tmp[0].type, NUMBER_LITERAL);
	}

	TEST_CASE("lexer-recognises-reserved-words") {
		Lexer lx;
		std::string testProgram;
		SUBCASE("and") { testProgram = "and "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, AND); }
		SUBCASE("break") { testProgram = "break "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, BREAK); }
		SUBCASE("do") { testProgram = "do "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, DO); }
		SUBCASE("else") { testProgram = "else "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, ELSE); }
		SUBCASE("elseif") { testProgram = "elseif "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, ELSEIF); }
		SUBCASE("end") { testProgram = "end "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, END); }
		SUBCASE("false") { testProgram = "false "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, FALSE); }
		SUBCASE("for") { testProgram = "for "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, FOR); }
		SUBCASE("function") { testProgram = "function "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, FUNCTION); }
		SUBCASE("goto") { testProgram = "goto "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, GOTO); }
		SUBCASE("if") { testProgram = "if "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, IF); }
		SUBCASE("in") { testProgram = "in "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, IN); }
		SUBCASE("local") { testProgram = "local "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, LOCAL); }
		SUBCASE("nil") { testProgram = "nil "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, NIL); }
		SUBCASE("not") { testProgram = "not "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, NOT); }
		SUBCASE("or") { testProgram = "or "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, OR); }
		SUBCASE("repeat") { testProgram = "repeat "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, REPEAT); }
		SUBCASE("return") { testProgram = "return "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, RETURN); }
		SUBCASE("then") { testProgram = "then "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, THEN); }
		SUBCASE("true") { testProgram = "true "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, TRUE); }
		SUBCASE("until") { testProgram = "until "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, UNTIL); }
		SUBCASE("while") { testProgram = "while "; std::vector<Token> tmp = lx.parse(testProgram); CHECK_EQ(tmp[0].type, WHILE); }
	}
	TEST_CASE("lexer-recognises-identifiers") {
		Lexer lx;
		std::string testProgram;
		SUBCASE("try identifier - randomName") { testProgram = "randomName "; }
		SUBCASE("try identifier - rand1Name") { testProgram = "rand1Name "; } 
		SUBCASE("try identifier - randName22") { testProgram = "randName22 "; }
		SUBCASE("try identifier - returnName123") { testProgram = "returnName123 "; }

		std::vector<Token> tmp = lx.parse(testProgram);
		CHECK_EQ(tmp[0].type, IDENTIFIER);
	}
	TEST_CASE("lexer-recognises-sequence of tokens") {
		Lexer lx;
		std::string testProgram;
		SUBCASE("small function with identifier") { 
			testProgram = "function functionName(n) ";
			std::vector<Token> tmp = lx.parse(testProgram); 
			std::vector<TokenType> res;
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			/* std::vector<TokenType> answer = {FUNCTION, WHITESPACE, IDENTIFIER, WHITESPACE, L_PARENT, IDENTIFIER, R_PARENT }; */
			std::vector<TokenType> answer;
			answer.push_back(FUNCTION);
			/* answer.push_back(WHITESPACE); */
			answer.push_back(IDENTIFIER);
			answer.push_back(L_PARENT);
			answer.push_back(IDENTIFIER);
			answer.push_back(R_PARENT);
			/* answer.push_back(WHITESPACE); */
			CHECK_EQ(res, answer);
		}
		
		SUBCASE("small function with number") { 
			testProgram = "function functionName(2) ";
			std::vector<Token> tmp = lx.parse(testProgram); 
			std::vector<TokenType> res;
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			std::vector<TokenType> answer = {FUNCTION, IDENTIFIER, L_PARENT, NUMBER_LITERAL, R_PARENT };
			CHECK_EQ(res, answer);
		}
		
		SUBCASE("function declaration test") { 
			testProgram = "function functionName(2) {anotherName=3} ";
			std::vector<Token> tmp = lx.parse(testProgram); 
			std::vector<TokenType> res;
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			std::vector<TokenType> answer = {FUNCTION, IDENTIFIER, L_PARENT, NUMBER_LITERAL, R_PARENT,
			L_BRACE, IDENTIFIER, ASSIGN, NUMBER_LITERAL, R_BRACE };
			CHECK_EQ(res, answer);
		}
	}
	TEST_CASE("tests with strings") { 
		
		Lexer lx;
		std::string testProgram;
		std::vector<Token> tmp;
		std::vector<TokenType> res;

		SUBCASE("small function accepting string with double quotes ") { 
			testProgram = "function functionName(\"this is a string\") "; 

			tmp = lx.parse(testProgram); 
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			std::vector<TokenType> answer = {FUNCTION, IDENTIFIER, L_PARENT, STRING_LITERAL, R_PARENT};
			
			CHECK_EQ(res, answer);
		}
		SUBCASE("small function accepting string with quotes ") { 
			testProgram = "function functionName('this is a string') "; 

			tmp = lx.parse(testProgram); 
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			std::vector<TokenType> answer = {FUNCTION, IDENTIFIER, L_PARENT, STRING_LITERAL, R_PARENT };
			
			CHECK_EQ(res, answer);
		}
		SUBCASE("testing inside string for all the symbols") { 
			testProgram = "function functionName('(){}[]+-*%^#= == <= >= ~= > >> < << / // : :: ; , . .. ... & | ') "; 

			tmp = lx.parse(testProgram); 
			for (auto& el : tmp) {
				res.push_back(el.type);
			}
			std::vector<TokenType> answer = {FUNCTION, IDENTIFIER, L_PARENT, STRING_LITERAL, R_PARENT };
			
			CHECK_EQ(res, answer);
		}
		
	}
}
