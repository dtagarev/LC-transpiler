#include "lexer.hpp"
#include "tokens.hpp"

using tokenArray = Lexer::tokenArray;

tokenArray Lexer::parse(const std::string& program) {
	tokenArray tokens;
	Token currToken;
	
	for(const char& currCh : program) { 

	  //to-do string escape sequence and comments (do we need new line as a comment?)
		
		switch (currCh) {
			case ' ':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //ends the previous token;
					currToken.type = WHITESPACE;
					currToken.text.append(1, currCh);
					endToken(currToken, tokens);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '\n': //support inside string?
			case '\r':
				endToken(currToken, tokens);
				currToken.lineNumber += 1;
				break;
			case'\t':
			case'\v':
				endToken(currToken, tokens);
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				if(currToken.type != STRING_LITERAL) {
					if(currToken.type != NUMBER_LITERAL) {
						endToken(currToken, tokens);
					}
					currToken.type = NUMBER_LITERAL;
					currToken.text.append(1, currCh);
				} else { 
					currToken.text.append(1, currCh);
				}
				/* if(currToken.type == NULLTOKEN) { */
				/* 	currToken.type = NUMBER_LITERAL; */
				/* 	currToken.text.append(1, currCh); */
				/* } else { */
				/* 	currToken.text.append(1, currCh); */
				/* } */
				break;
			case '(':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = L_PARENT;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case ')':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = R_PARENT;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '{':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = L_BRACE;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '}':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = R_BRACE;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '[':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = L_BRACKET;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case ']':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = R_BRACKET;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '+':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = PLUS;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '-':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = MINUS;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '*':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = STAR;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '%':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = PERCENT;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '^':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = EXP;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '#':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = SH;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '=':
				if(currToken.type == ASSIGN) { 
					currToken.type = EQUAL;
					currToken.text.append(1, currCh);
				} else if(currToken.type == LESS_THAN) {
					currToken.type = LESS_OR_EQUAL;
					currToken.text.append(1, currCh);
				} else if(currToken.type == GREATER_THAN) {
					currToken.type = GREATER_OR_EQUAL;
					currToken.text.append(1, currCh);
				} else if(currToken.type == TILDE) {
					currToken.type = NOT_EQUAL;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) { // catches the one equal sign
					endToken(currToken, tokens); //end the previous token;
					currToken.type = ASSIGN;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '<':
				if(currToken.type == LESS_THAN) {
					currToken.type = DOUBLE_LESS_THAN;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) { // catches the one equal sign
					endToken(currToken, tokens); //end the previous token;
					currToken.type = LESS_THAN;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '>':
				if(currToken.type == GREATER_THAN) {
					currToken.type = DOUBLE_GREATER_THAN;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) { // catches the one equal sign
					endToken(currToken, tokens); //end the previous token;
					currToken.type = GREATER_THAN;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '/':
				if(currToken.type == SLASH ) {
					currToken.type = DOUBLE_SLASH;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = SLASH;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case '~':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = TILDE;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case ':':
				if(currToken.type == COLON ) {
					currToken.type = DOUBLE_COLON;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = COLON;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case';':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = SEMI_COLON;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case',':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = COMMA;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case'.':
				if(currToken.type == NUMBER_LITERAL) {
					currToken.text.append(1, currCh);
				}
				else if(currToken.type == DOT ) {
					currToken.type = DOUBLE_DOT;
					currToken.text.append(1, currCh);
				} else if(currToken.type == DOUBLE_DOT) {
					currToken.type = ELLIPSIS;
					currToken.text.append(1, currCh);
				} else if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = DOT;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case'&':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = AMPERSAND;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case'|':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = PIPE;
					currToken.text.append(1, currCh);
				} else {
					currToken.text.append(1, currCh);
				}
				break;
			case'"':
			case '\'':
				if(currToken.type != STRING_LITERAL) {
					endToken(currToken, tokens); //end the previous token;
					currToken.type = STRING_LITERAL;
					if(currCh != '\'' && currCh != '"')
						currToken.text.append(1, currCh);

				} else if(currToken.type == STRING_LITERAL){ // does it contain the chars " and ' ?? and does it contain the last one because we dont add the last but the first one we do.
					endToken(currToken ,tokens); 
				}
				break;
			default:
				if(currToken.type != STRING_LITERAL) {
					if(currToken.type != IDENTIFIER) {
						endToken(currToken, tokens);
					}
					currToken.type = IDENTIFIER;
					currToken.text.append(1, currCh);
				} else { 
					currToken.text.append(1, currCh);
				}
				break;
		}
	}
	
	return tokens;
}
void Lexer::endToken(Token& token, tokenArray& arr) {
	if(token.type == IDENTIFIER) {
		reservedWordCheck(token);	
	}
	if(token.type != NULLTOKEN && token.type != WHITESPACE) {
		arr.push_back(token);
	}
	token.type = NULLTOKEN;
	token.text.erase();
}
void Lexer::reservedWordCheck(Token& token) {
	if(token.text == "and") {
		token.type = AND;
	} else if(token.text == "break") {
		token.type = BREAK;
	} else if(token.text == "do") {
		token.type = DO;
	} else if(token.text == "else") {
		token.type = ELSE;
	} else if(token.text == "elseif") {
		token.type = ELSEIF;
	} else if(token.text == "end") {
		token.type = END;
	} else if(token.text == "false") {
		token.type = FALSE;
	} else if(token.text == "for") {
		token.type = FOR;
	} else if(token.text == "function") {
		token.type = FUNCTION;
	} else if(token.text == "goto") {
		token.type = GOTO;
	} else if(token.text == "if") {
		token.type = IF;
	} else if(token.text == "in") {
		token.type = IN;
	} else if(token.text == "local") {
		token.type = LOCAL;
	} else if(token.text == "nil") {
		token.type = NIL;
	} else if(token.text == "not") {
		token.type = NOT;
	} else if(token.text == "or") {
		token.type = OR;
	} else if(token.text == "repeat") {
		token.type = REPEAT;
	} else if(token.text == "return") {
		token.type = RETURN;
	} else if(token.text == "then") {
		token.type = THEN;
	} else if(token.text == "true") {
		token.type = TRUE;
	} else if(token.text == "until") {
		token.type = UNTIL;
	} else if(token.text == "while") {
		token.type = WHILE;
	} else if(token.text == "print") {
		token.type = PRINT;
	}
}
