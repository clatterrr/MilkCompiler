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
	
	SyntaxToken cur = Peek(0);
	++_position;
	Current = Peek(0);
	return cur;
}

SyntaxTree Parser::ParseMe()
{
	SyntaxTree tree;
	ExpressionSyntax left = ParseCurrentExpression();
	while (1)
	{
		if (_position >= _tokens.size())
			break;

		if (Current._kind != SyntaxKind::PlusToken && Current._kind != SyntaxKind::MinusToken &&
			Current._kind != SyntaxKind::StarToken && Current._kind != SyntaxKind::SlashToken)
			break;
		left._MyIdx = tree.ExpVec.size();
		if (left._MyKind == SyntaxKind::NumberToken)
		{
			printf("now left value is %d\n", left._MainToken._NumberValue);
		}
		else
		{
			printf("now op is %s\n", left._MainToken._text.c_str());
		}

		tree.ExpVec.push_back(left);
		SyntaxToken operatorToken = NextToken();
		if (operatorToken._kind == SyntaxKind::NumberToken)
		{
			printf("now operatorToken value is %d\n", operatorToken._NumberValue);
		}
		else
		{
			printf("now op is %s\n", operatorToken._text.c_str());
		}
		ExpressionSyntax right = ParseCurrentExpression();
		right._MyIdx = tree.ExpVec.size();
		tree.ExpVec.push_back(right);
		if (right._MyKind == SyntaxKind::NumberToken)
		{
			printf("now right value is %d\n", right._MainToken._NumberValue);
		}
		else
		{
			printf("now op is %s\n", right._MainToken._text.c_str());
		}

		ExpressionSyntax mainExp(left._MyIdx, left._MyKind, operatorToken, right._MyIdx, right._MyKind);
		mainExp._MyIdx = tree.ExpVec.size();
		tree.ExpVec.push_back(mainExp);
		left = mainExp;
	}
	tree._Root = left;
	return tree;
}

ExpressionSyntax Parser::ParseCurrentExpression()
{
	SyntaxToken cur = Peek(0);
	_position++;
	Current = Peek(0);
	if (cur._kind == SyntaxKind::NumberToken)
	{
		return ExpressionSyntax(cur);
	}
}



ExpressionSyntax Parser::ParsePrimaryExpression()
{
	if (Current._kind == SyntaxKind::OpenParenthesisToken)
	{
		SyntaxToken left = NextToken();
	//	ExpressionSyntax expression = ParseExpression();
		SyntaxToken  right = Match(SyntaxKind::CloseParenthesisToken);
		//return ExpressionSyntax(left, expression, right);
	}

	SyntaxToken numberToken = Match(SyntaxKind::NumberToken);
	return ExpressionSyntax(numberToken);
}

SyntaxToken Parser::Match(SyntaxKind kind)
{
	if (Current._kind == kind)
		return NextToken();
	return SyntaxToken(kind, Current._position, " ");
}
