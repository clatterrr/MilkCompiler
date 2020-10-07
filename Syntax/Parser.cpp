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
	tree._Root = ParseEntireLineAsStatement();
	return tree;
}

StatementSyntax Parser::ParseEntireLineAsStatement()
{
	switch (_tokens[0]._kind)
	{
	case SyntaxKind::IntKeyWord:
	{
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(3, _tokens.size()-1);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], _tokens[1], _tokens[2], mainExpOfTheLine._MyIdx);
	}
	case SyntaxKind::IdentifierToken:
	{
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(2, _tokens.size() - 1);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], _tokens[1], mainExpOfTheLine._MyIdx);
	}
	case SyntaxKind::PrintKeyWord:
	{
		//因为print有一前一后两个括号
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(2, _tokens.size() - 2);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], mainExpOfTheLine._MyIdx);
	}
	case SyntaxKind::IfKeyWord:
	{
		//因为If有一前一后两个括号
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(2, _tokens.size() - 2);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], mainExpOfTheLine._MyIdx);
	}
	default:
		break;
	}
	return StatementSyntax();
}

//把这一行解析为Statement，揪出一个根作为_Root
ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end)
{
	printf("处理从%d到%d\n", start, end);
	int nextOpIdx = start + 1;
	ExpressionSyntax left;
	printf("左侧未定义！\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken:
	{
		left = ExpressionSyntax(_tokens[start]);
		PushTree(left);
		printf("左侧的值为%d\n", left._Token0._NumberValue);
		break;
	}
	case SyntaxKind::NOTToken:
	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken:
	{
		if (_tokens[start + 1]._kind == SyntaxKind::NumberToken)
		{
			printf("一元运算符右边是数字\n");
			ExpressionSyntax num = ExpressionSyntax(_tokens[start + 1]);
			PushTree(num);
			left = ExpressionSyntax(_tokens[start], num._MyIdx);
			nextOpIdx += 1;
			PushTree(left);
		}
		else if (_tokens[start + 1]._kind == SyntaxKind::OpenParenthesisToken)
		{
			printf("一元运算符右边是括号\n");
			ExpressionSyntax post = ParseFixedLenExpression(start + 1, end);
			PushTree(post);
			return ExpressionSyntax(_tokens[start], post._MyIdx);
		}
		break;
	}
	case SyntaxKind::OpenParenthesisToken:
	{

		int ParentTheses = 1;
		for (int i = start + 1; i <= end; i++)
		{
			if (_tokens[i]._kind == SyntaxKind::OpenParenthesisToken)ParentTheses++;
			if (_tokens[i]._kind == SyntaxKind::CloseParenthesisToken)ParentTheses--;
			if (ParentTheses == 0)
			{
				left = ParseFixedLenExpression(start + 1, i - 1);
				PushTree(left);
				nextOpIdx = i + 1;
				break;
			}
		}
		break;
	}
	case SyntaxKind::IdentifierToken:
	{
		left = ExpressionSyntax(_tokens[start]);
		PushTree(left);
		printf("左侧的文本为%s\n", left._Token0._text.c_str());
		break;
	}
	default:
		break;
	}
	if (nextOpIdx > end)
		return left;
	return NextExpression(nextOpIdx, end, left);
}

//一律返回构造函数，返回之后才能算索引
ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end, ExpressionSyntax left, SyntaxToken oper)
{
	printf("处理从%d到%d\n", start, end);
	int nextOpIdx = start + 1;
	ExpressionSyntax temp;
	printf("左侧已定义！\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken://纯数字，那么就将合并成为表达式
	{
		temp = ExpressionSyntax(_tokens[start]); PushTree(temp);
		printf("现在的临时值为%d\n", temp._Token0._NumberValue);
		left = ExpressionSyntax(left._MyIdx, oper, temp._MyIdx);
		PushTree(left);
		break;
	}
	case SyntaxKind::NOTToken:
	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken://负数，之后再讨论，现在先不做任何处理
	{
		if (_tokens[start + 1]._kind == SyntaxKind::NumberToken)
		{
			printf("一元运算符右边是数字\n");
			ExpressionSyntax num = ExpressionSyntax(_tokens[start + 1]);
			PushTree(num);
			left = ExpressionSyntax(_tokens[start], num._MyIdx);
			nextOpIdx += 1;
			PushTree(left);
		}
		else if (_tokens[start + 1]._kind == SyntaxKind::OpenParenthesisToken)
		{
			printf("一元运算符右边是括号\n");
			ExpressionSyntax post = ParseFixedLenExpression(start + 1, end);
			PushTree(post);
			return ExpressionSyntax(_tokens[start], post._MyIdx);
		}
		break;
	}
	case SyntaxKind::OpenParenthesisToken:
	{
		int ParentTheses = 1;
		for (int i = start + 1; i <= end; i++)
		{
			if (_tokens[i]._kind == SyntaxKind::OpenParenthesisToken)ParentTheses++;
			if (_tokens[i]._kind == SyntaxKind::CloseParenthesisToken)ParentTheses--;
			if (ParentTheses == 0)
			{
				temp = ParseFixedLenExpression(start + 1, i -1);
				PushTree(temp);
				left = ExpressionSyntax(left._MyIdx, oper, temp._MyIdx);
				PushTree(left);
				nextOpIdx = i + 1;
				break;
			}
		}
		break;
	}
	case SyntaxKind::IdentifierToken:
	{
		left = ExpressionSyntax(_tokens[start]);
		PushTree(left);
		printf("左侧的文本为%s\n", left._Token0._text.c_str());
		break;
	}
	default:break;
	}
	if (nextOpIdx > end)
		return left;
	return NextExpression(nextOpIdx, end, left);

}

ExpressionSyntax Parser::NextExpression(int nextOpIdx, int end, ExpressionSyntax left)
{
	if (nextOpIdx >= end)
	{
		return left;
	}
	ExpressionSyntax right;
	switch (_tokens[nextOpIdx]._kind)
	{
	case SyntaxKind::MinusToken:
	case SyntaxKind::PlusToken:
	{
		right = ParseFixedLenExpression(nextOpIdx + 1, end);
		PushTree(right);
		printf("遇到一个加减！\n");
		return ExpressionSyntax(left._MyIdx, _tokens[nextOpIdx], right._MyIdx);
	}

	case SyntaxKind::StarToken:
	case SyntaxKind::SlashToken:		printf("遇到一个乘除！\n"); return ParseFixedLenExpression(nextOpIdx + 1, end, left, _tokens[nextOpIdx]);
	default:
		break;
	}
}



void Parser::PushTree(ExpressionSyntax &exp)
{
	exp._MyIdx = tree.ExpVec.size();
	tree.ExpVec.push_back(exp);
}
