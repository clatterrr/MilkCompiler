#ifndef SYNTAXTOKEN_H
#define SYNTAXTOKEN_H

#include<string>
#include "SyntaxKind.h"
using namespace std;


class SyntaxToken
{
public:
	SyntaxToken() = default;
	SyntaxToken(SyntaxKind kind,int position,int value);
	SyntaxToken(SyntaxKind kind, int position, string text);
	~SyntaxToken();

	SyntaxKind _kind;
	int _position;
	string _text;
	int _NumberValue;
};



#endif // !SYNTAXTOKEN_H


