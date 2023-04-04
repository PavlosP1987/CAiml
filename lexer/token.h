/* 04 April 2023 */

/* token.h : Header file that includes all tokens */

#ifndef __TOKEN_H__
#define __TOKEN_H__

enum Token {
	tok_eof = -1;
	
	tok_inj = -2,
	tok_extern = -3,
	
	tok_identifier = -4,
	tok_number = -5,
};

#endif