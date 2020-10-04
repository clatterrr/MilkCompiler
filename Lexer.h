#ifndef  LEXER_H
#define LEXER_H

#include<string>
#include "SyntaxToken.h"
using namespace std;

class Lexer
{
public:
	Lexer(string text);
	~Lexer();

	int _position;
	string _text;

	char CurrentChar();
	SyntaxToken NextToken();

	bool IsDigit(char c);
	bool IsWhiteSpace(char c);
	bool IsLetter(char c);

};



#endif // ! LEXER_H


