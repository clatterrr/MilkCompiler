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

SyntaxTree Parser::ParseMe()
{
	BasicExp exp = ParseExpression();
	SyntaxToken endOfFile = Match(SyntaxKind::EndOfFile);
	return SyntaxTree(exp, endOfFile);
}


BasicExp Parser::ParseExpression()
{
	BasicExp left = ParsePrimaryExpression();
	while (1)
	{
		if (_position >= _tokens.size())
			break;
		Current = Peek(0);//现在Current就是那个运算符

		if (left._Kind == SyntaxKind::NumberToken)
		{
			printf("now left value is %d\n", left._MainToken._NumberValue);
		}
		else
		{
			printf("now op is %s\n", left._MainToken._text.c_str());
		}
		if (Current._kind == SyntaxKind::NumberToken)
		{
			printf("now Current value is %d\n", Current._NumberValue);
		}
		else
		{
			printf("now op is %s\n", Current._text.c_str());
		}
		if (Current._kind != SyntaxKind::PlusToken && Current._kind != SyntaxKind::MinusToken)
			break;

		SyntaxToken operatorToken = NextToken();

		Current = Peek(0);//推进到右边的数字
		if (Current._kind == SyntaxKind::NumberToken)
		{
			printf("now right value is %d\n", Current._NumberValue);
		}
		else
		{
			printf("now op is %s\n", Current._text.c_str());
		}
		BasicExp right = ParsePrimaryExpression();

		left = BasicExp(left,left._Kind,operatorToken,right,right._Kind);

	}
	return left;
}

BasicExp Parser::ParsePrimaryExpression()
{
	if (Current._kind == SyntaxKind::OpenParenthesisToken)
	{
		SyntaxToken left = NextToken();
		ExpressionSyntax expression = ParseExpression();
		SyntaxToken  right = Match(SyntaxKind::CloseParenthesisToken);
		return BasicExp(left, expression, right);
	}

	SyntaxToken numberToken = Match(SyntaxKind::NumberToken);
	return BasicExp(numberToken);
}

SyntaxToken Parser::Match(SyntaxKind kind)
{
	if (Current._kind == kind)
		return NextToken();
	return SyntaxToken(kind, Current._position, "");
}
