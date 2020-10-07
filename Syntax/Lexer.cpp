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
		return  SyntaxToken(SyntaxKind::EndOfFile, 0, " ");
	}


	int start = _position;
	char Current = _text[_position];
	switch (Current)
	{
		//‘ÀÀ„∑˚¥¶¿Ì
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
	case '=':
		return SyntaxToken(SyntaxKind::EqualToken, _position++, "=");
	case '1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':case'0':
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
		return SyntaxToken(SyntaxKind::NumberToken, 0, result);
	}
	default:
	{

		if (IsLetter(Current))
		{
			while (IsLetter(_text[_position]))
			{
				_position++;
			}
			int length = _position - start;
			string tempText(_text, start, length);
			SyntaxKind kind = GetTextKind(tempText);
			return SyntaxToken(kind, 0, tempText);
		}
		else if (IsWhiteSpace(Current))
		{
			while (IsWhiteSpace(_text[_position]))
			{
				_position++;
			}
			int length = _position - start;
			string tempText(_text, start, length);
			return SyntaxToken(SyntaxKind::WhitespaceToken, 0, tempText);
		}
	}
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

SyntaxKind Lexer::GetTextKind(string str)
{
	if (str == "int")
	{
		return SyntaxKind::IntKeyWord;
	}
	else if (str == "if")
	{
		return SyntaxKind::IfKeyWord;
	}
	else if (str == "print")
	{
		return SyntaxKind::PrintKeyWord;
	}
	else
	{
		return SyntaxKind::IdentifierToken;
	}
}
