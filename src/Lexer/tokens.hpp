#ifndef TOKENS
#define TOKENS

#include <string>
#include <iostream>

enum TokenType {
	NULLTOKEN,
	WHITESPACE, // just a space
	NUMBER_LITERAL,
	STRING_LITERAL,
	STRING_ESCAPE_SEQUENCE,
	//Operators
	L_PARENT, // (
	R_PARENT, // )
	L_BRACE, // {
	R_BRACE, // }
	L_BRACKET, // [
	R_BRACKET, // ]
	PLUS, // +
	MINUS, // - 
	STAR, // * 
	PERCENT, // %
	EXP, // ^ 
	SH, //#
	//multicharacter operators
	ASSIGN, // =
	EQUAL, // ==
	LESS_OR_EQUAL, // <=
	GREATER_OR_EQUAL, // >=
	NOT_EQUAL, // ~=
	LESS_THAN, // <
	DOUBLE_LESS_THAN, // << 
	GREATER_THAN, // >
	DOUBLE_GREATER_THAN, // >>
	SLASH, // / 
	DOUBLE_SLASH, // //
	TILDE, // ~
	COLON, // :
	DOUBLE_COLON, // ::
	SEMI_COLON, //;
	COMMA, // ,
	DOT, // .
	DOUBLE_DOT, // ..
	ELLIPSIS, // ...
	AMPERSAND, // &
	PIPE, // | 
	//keywords
	IDENTIFIER, 
	AND,
	BREAK,
	DO,
	ELSE,
	ELSEIF,
	END,
	FALSE,
	FOR,
	FUNCTION,
	GOTO,
	IF,
	IN,
	LOCAL,
	NIL,
	NOT,
	OR,
	REPEAT,
	RETURN,
	THEN,
	TRUE,
	UNTIL,
	WHILE,
	//base library tokens
	PRINT,
	//more on the site
	//comments?
};

static const char *printToken[] {
	"NULLTOKEN",
	"WHITESPACE", // just a space
	"NUMBER_LITERAL",
	"STRING_LITERAL",
	"STRING_ESCAPE_SEQUENCE",
	//Operators
	"L_PARENT", // (
	"R_PARENT", // )
	"L_BRACE", // {
	"R_BRACE", // }
	"L_BRACKET", // [
	"R_BRACKET", // ]
	"PLUS", // +
	"MINUS", // - 
	"STAR", // * 
	"PERCENT", // %
	"EXP", // ^ 
	"SH", //#
	//multicharacter operators
	"ASSIGN", // =
	"EQUAL", // ==
	"LESS_OR_EQUAL", // <=
	"GREATER_OR_EQUAL", // >=
	"NOT_EQUAL", // ~=
	"LESS_THAN", // <
	"DOUBLE_LESS_THAN", // << 
	"GREATER_THAN", // >
	"DOUBLE_GREATER_THAN", // >>
	"SLASH", // / 
	"DOUBLE_SLASH", // //
	"TILDE", // ~
	"COLON", // :
	"DOUBLE_COLON", // ::
	"SEMI_COLON", //;
	"COMMA", // ,
	"DOT", // .
	"DOUBLE_DOT", // ..
	"ELLIPSIS", // ...
	"AMPERSAND", // &
	"PIPE", // | 
	//keywords
	"IDENTIFIER", 
	"AND",
	"BREAK",
	"DO",
	"ELSE",
	"ELSEIF",
	"END",
	"FALSE",
	"FOR",
	"FUNCTION",
	"GOTO",
	"IF",
	"IN",
	"LOCAL",
	"NIL",
	"NOT",
	"OR",
	"REPEAT",
	"RETURN",
	"THEN",
	"TRUE",
	"UNTIL",
	"WHILE",
	//base library tokens
	"PRINT"
};

class Token {
public:
	enum TokenType type { NULLTOKEN };
	std::string text;
	size_t lineNumber { 1 };

	void debugPrint() { std::cout << "Token(" << printToken[type] << ", \"" << text << "\", " << lineNumber << ")" << std::endl; };
};

#endif
