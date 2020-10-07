#ifndef  LEXER_H
#define LEXER_H

#include<string>
#include "SyntaxNode.h"
using namespace std;

class Lexer
{
public:
	Lexer(string text);
	~Lexer();

	int _position;
	string _text;
public:
	char CurrentChar();
	SyntaxToken NextToken();

	bool IsDigit(char c);
	bool IsWhiteSpace(char c);
	bool IsLetter(char c);
	SyntaxKind GetTextKind(string str);

};



#endif // ! LEXER_H


