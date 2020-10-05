#ifndef SYNTAXTOKEN_H
#define SYNTAXTOKEN_H

#include<string>
using namespace std;


enum class SyntaxKind
{
	NumberToken,
	WhitespaceToken,
	PlusToken,
	MinusToken,
	StarToken,
	SlashToken,
	OpenParenthesisToken,
	CloseParenthesisToken,
	ThesisExpression,
	BinaryExpression,
	EndOfFile
};

class SyntaxToken
{
public:
	SyntaxToken() = default;
	SyntaxToken(SyntaxKind kind,int position,string text,int value);
	SyntaxToken(SyntaxKind kind, int position, string text);
	~SyntaxToken();

	SyntaxKind _kind;
	int _position;
	string _text;
	int _NumberValue;
};



#endif // !SYNTAXTOKEN_H


