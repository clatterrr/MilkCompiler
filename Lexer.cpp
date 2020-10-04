#include "Lexer.h"

Lexer::Lexer(string text)
{
    _text = text;
	_position = 0;
}

Lexer::~Lexer()
{
}

char Lexer::CurrentChar()
{
	if (_position > _text.size())
	{
		return '\0';
	}
	
	return _text[_position];
}

SyntaxToken Lexer::NextToken()
{
	if (_position > _text.size())
	{
		return  SyntaxToken(EndOfFile, 0, _text);
	}


	int start = _position;
	char Current = _text[_position];
	if (IsDigit(Current))//number 0~9
	{
		while (IsDigit(_text[_position]))
		{
			_position++;
		}
		int length = _position - start;
		string tempText(_text, start, length);
		int result = 0;
		for (int i = 0; i < length; i++)
		{
			result = result * 10 + tempText[i] - '0';
		}
		return SyntaxToken(NumberToken, 0, _text, result);
	}

	if (IsWhiteSpace(Current))
	{
		while (IsWhiteSpace(_text[_position]))
		{
			_position++;
		}
		int length = _position - start;
		string tempText(_text, start, length);
		return SyntaxToken(WhitespaceToken, 0, _text);
	}


	if (IsLetter(Current))
	{
		while (IsLetter(_text[_position]))
		{
			_position++;
		}
		int length = _position - start;
		string tempText(_text, start, length);
		return SyntaxToken(NumberToken, 0, _text);
	}

	switch (Current)
	{
	case '+':
		return  SyntaxToken(PlusToken, _position++, "+");
	case '-':
		return  SyntaxToken(MinusToken, _position++, "-");
	case '*':
		return  SyntaxToken(StarToken, _position++, "*");
	case '/':
		return  SyntaxToken(SlashToken, _position++, "/");
	case '(':
		return  SyntaxToken(OpenParenthesisToken, _position++, "(");
	case ')':
		return  SyntaxToken(CloseParenthesisToken, _position++, ")");
	}
}

bool Lexer::IsDigit(char c)
{
	return (c >= 48) && (c <= 57);
}

bool Lexer::IsWhiteSpace(char c)
{
	return c == '\0';
}

bool Lexer::IsLetter(char c)
{
	return ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122));
}
