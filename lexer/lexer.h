/* 04 April 2023 */

/* lexer.h : Header file that includes all lexer commands and tokens
that are going to be parsed. */

#ifndef __LEXER_H__
#define __LEXER_H__

#include <cstdlib>
#include <string>

extern int CurTok;
int gettok();
int getNextToken();

extern std::string IdentifierStr;

extern double NumVal;

#endif