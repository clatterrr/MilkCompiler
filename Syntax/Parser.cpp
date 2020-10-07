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
		//��Ϊprint��һǰһ����������
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(2, _tokens.size() - 2);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], mainExpOfTheLine._MyIdx);
	}
	case SyntaxKind::IfKeyWord:
	{
		//��ΪIf��һǰһ����������
		ExpressionSyntax mainExpOfTheLine = ParseFixedLenExpression(2, _tokens.size() - 2);
		PushTree(mainExpOfTheLine);
		return StatementSyntax(_tokens[0], mainExpOfTheLine._MyIdx);
	}
	default:
		break;
	}
	return StatementSyntax();
}

//����һ�н���ΪStatement������һ������Ϊ_Root
ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end)
{
	printf("�����%d��%d\n", start, end);
	int nextOpIdx = start + 1;
	ExpressionSyntax left;
	printf("���δ���壡\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken:
	{
		left = ExpressionSyntax(_tokens[start]);
		PushTree(left);
		printf("����ֵΪ%d\n", left._Token0._NumberValue);
		break;
	}
	case SyntaxKind::NOTToken:
	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken:
	{
		if (_tokens[start + 1]._kind == SyntaxKind::NumberToken)
		{
			printf("һԪ������ұ�������\n");
			ExpressionSyntax num = ExpressionSyntax(_tokens[start + 1]);
			PushTree(num);
			left = ExpressionSyntax(_tokens[start], num._MyIdx);
			nextOpIdx += 1;
			PushTree(left);
		}
		else if (_tokens[start + 1]._kind == SyntaxKind::OpenParenthesisToken)
		{
			printf("һԪ������ұ�������\n");
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
		printf("�����ı�Ϊ%s\n", left._Token0._text.c_str());
		break;
	}
	default:
		break;
	}
	if (nextOpIdx > end)
		return left;
	return NextExpression(nextOpIdx, end, left);
}

//һ�ɷ��ع��캯��������֮�����������
ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end, ExpressionSyntax left, SyntaxToken oper)
{
	printf("�����%d��%d\n", start, end);
	int nextOpIdx = start + 1;
	ExpressionSyntax temp;
	printf("����Ѷ��壡\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken://�����֣���ô�ͽ��ϲ���Ϊ���ʽ
	{
		temp = ExpressionSyntax(_tokens[start]); PushTree(temp);
		printf("���ڵ���ʱֵΪ%d\n", temp._Token0._NumberValue);
		left = ExpressionSyntax(left._MyIdx, oper, temp._MyIdx);
		PushTree(left);
		break;
	}
	case SyntaxKind::NOTToken:
	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken://������֮�������ۣ������Ȳ����κδ���
	{
		if (_tokens[start + 1]._kind == SyntaxKind::NumberToken)
		{
			printf("һԪ������ұ�������\n");
			ExpressionSyntax num = ExpressionSyntax(_tokens[start + 1]);
			PushTree(num);
			left = ExpressionSyntax(_tokens[start], num._MyIdx);
			nextOpIdx += 1;
			PushTree(left);
		}
		else if (_tokens[start + 1]._kind == SyntaxKind::OpenParenthesisToken)
		{
			printf("һԪ������ұ�������\n");
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
		printf("�����ı�Ϊ%s\n", left._Token0._text.c_str());
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
		printf("����һ���Ӽ���\n");
		return ExpressionSyntax(left._MyIdx, _tokens[nextOpIdx], right._MyIdx);
	}

	case SyntaxKind::StarToken:
	case SyntaxKind::SlashToken:		printf("����һ���˳���\n"); return ParseFixedLenExpression(nextOpIdx + 1, end, left, _tokens[nextOpIdx]);
	default:
		break;
	}
}



void Parser::PushTree(ExpressionSyntax &exp)
{
	exp._MyIdx = tree.ExpVec.size();
	tree.ExpVec.push_back(exp);
}
