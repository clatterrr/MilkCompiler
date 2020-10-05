#include "SyntaxToken.h"


SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text,int value)
{
	_kind = kind;
	_position = position;
	_text = text;
	_NumberValue = value;
}

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text)
{
	_kind = kind;
	_position = position;
	_text = text;
	_NumberValue = -11;
}

SyntaxToken::~SyntaxToken()
{
}
