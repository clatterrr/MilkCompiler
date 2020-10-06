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
	if (_position >= _text.size())
	{
		return  SyntaxToken(SyntaxKind::EndOfFile, 0, _text);
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
		return SyntaxToken(SyntaxKind::NumberToken, 0, tempText, result);
	}

	if (IsWhiteSpace(Current))
	{
		while (IsWhiteSpace(_text[_position]))
		{
			_position++;
		}
		int length = _position - start;
		string tempText(_text, start, length);
		return SyntaxToken(SyntaxKind::WhitespaceToken, 0, tempText);
	}


	if (IsLetter(Current))
	{
		while (IsLetter(_text[_position]))
		{
			_position++;
		}
		int length = _position - start;
		string tempText(_text, start, length);
		return SyntaxToken(SyntaxKind::NumberToken, 0, tempText);
	}

	switch (Current)
	{
	case '+':
		return  SyntaxToken(SyntaxKind::PlusToken, _position++, "+");
	case '-':
		return  SyntaxToken(SyntaxKind::MinusToken, _position++, "-");
	case '*':
		return  SyntaxToken(SyntaxKind::StarToken, _position++, "*");
	case '/':
		return  SyntaxToken(SyntaxKind::SlashToken, _position++, "/");
	case '(':
		return  SyntaxToken(SyntaxKind::OpenParenthesisToken, _position++, "(");
	case ')':
		return  SyntaxToken(SyntaxKind::CloseParenthesisToken, _position++, ")");
	case '!':
		return SyntaxToken(SyntaxKind::NOTToken, _position++, "!");
	}
}

bool Lexer::IsDigit(char c)
{
	return (c >= 48) && (c <= 57);
}

bool Lexer::IsWhiteSpace(char c)
{
	return c == 32;
}

bool Lexer::IsLetter(char c)
{
	return ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122));
}
