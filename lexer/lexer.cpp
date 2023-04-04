/* 04 April 2023 */

/* lexer.cpp : is referenced to the Lexing Phase No1. */

/* needs improvement */

#include "lexer/lexer.h"
#include "lexer/token.h"

int CurTok;
std::string IdentifierStr;
double NumVal;

int gettok() {
	static int LastChar = ' ';
	
	while (isspace(LastChar)) {
		LastChar = getchar();
	}
	
	if (isalpha(LastChar)) {
		IdentifierStr = LastChar;
		
		while(isalnum(LastChar = getchar())) {
			IdentifierStr += LastChar;
		}
		
		if(IdentifierStr == "injection") { // or function injection()
			return tok_inj;
		}
		
		if(IdentifierStr == "extern") {
			return tok_extern;
		}
		
		return tok_identifier;
	}
	
	if (isdigit(LastChar) || LastChar == '.') {
		std::string NumStr;
		
		do {
			NumStr += LastChar;
			LastChar = getchar();
		} while (isdigit(LastChar) || LastChar == '.');
		
		NumVal = strtod(NumStr.c_str(), 0);
		return tok_number;
	}
	
	if (LastChar == '#') {
		do {
			LastChar = getchar();
		} while (LastChar != EOF && LastChar !='\n' && LastChar != '\r');
		
		if (LastChar != EOF) {
			return gettok();
		}
	}
	
	if (LastChar == EOF) {
		return tok_eof;
	}
	
	int ThisChar = LastChar;
	LastChar = getchar();
	return ThisChar;
}

int getNextToken() {
	return CurTok = gettok();
}