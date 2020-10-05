#include "Parser.h"

Parser::Parser(string text)
{
	Lexer lex(text);
	SyntaxToken token = lex.NextToken();
	while (token._kind != SyntaxKind::EndOfFile)
	{
		if (token._kind != SyntaxKind::WhitespaceToken)
			_tokens.push_back(token);
		token = lex.NextToken();
	}
	_position = 0;
	Current = Peek(0);
}

Parser::~Parser()
{
}

SyntaxToken Parser::Peek(int offset)
{
	int index = _position + offset;
	if (index >= _tokens.size())
		return _tokens[_tokens.size() - 1];
	return _tokens[index];
}

SyntaxToken Parser::NextToken()
{
	SyntaxToken cur = Current;
	++_position;
	return cur;
}

ExpressionSyntax Parser::Parse()
{
	ExpressionSyntax left = ParsePrimaryExpression();


	while (1)
	{
		Current = Peek(0);//现在Current就是那个运算符
		printf("left is %s\n", left._MainToken._text.c_str());

		if (Current._kind != SyntaxKind::PlusToken && Current._kind != SyntaxKind::MinusToken)
			break;
		SyntaxToken operatorToken = NextToken();
		printf("operatorToken is %s\n", operatorToken._text.c_str());
		Current = Peek(0);//推进到右边的数字
		printf("current is %s\n", Current._text.c_str());
		ExpressionSyntax right = ParsePrimaryExpression();

		ExpressionSyntax ComputeRes =  BinaryExp(left, operatorToken, right);
		 left = right;

	}
	return left;
}

ExpressionSyntax Parser::ParsePrimaryExpression()
{
	SyntaxToken numberToken = Match(SyntaxKind::NumberToken);

	return NumberExp(numberToken);
}

SyntaxToken Parser::Match(SyntaxKind kind)
{
	if (Current._kind == kind)
		return NextToken();
	return SyntaxToken(kind, Current._position, nullptr);
}
