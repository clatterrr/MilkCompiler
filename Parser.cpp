#include "Parser.h"

Parser::Parser(string text)
{
	Lexer lex(text);
	SyntaxToken token = lex.NextToken();
	while (token._kind != EndOfFile)
	{
		if (token._kind != WhitespaceToken)
			_tokens.push_back(token);
		token = lex.NextToken();
	}
   
}

Parser::~Parser()
{
}

SyntaxToken Parser::Peek(int offset)
{
	int index = _position + offset;
	if (index > _tokens.size())
		return _tokens[_tokens.size() - 1];
	return _tokens[index];
}
