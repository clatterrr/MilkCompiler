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

void Parser::IntoStack()
{
	bool ParentThesisFlag = false;
	for (int i = 0; i < _tokens.size(); i++)
	{
		switch (_tokens[i]._kind)
		{
		case SyntaxKind::NumberToken:_TokenStack.push_back(_tokens[i]);
		case SyntaxKind::MinusToken:
		case SyntaxKind::PlusToken:_TempOp.push(_tokens[i]);
		case SyntaxKind::StarToken:
		case SyntaxKind::SlashToken:
		{
			_TempOp.push(_tokens[i]);
			if (ParentThesisFlag)break;
			while (_TempOp.size())
			{
				_TokenStack.push_back(_TempOp.front());
				_TempOp.pop();
			}
			break;
		}
		case SyntaxKind::OpenParenthesisToken:
		{
			_TempOp.push(_tokens[i]);
			ParentThesisFlag = true;
			break;
		}
		case SyntaxKind::CloseParenthesisToken:
		{
			while (_TempOp.front()._kind != SyntaxKind::OpenParenthesisToken)
			{
				_TokenStack.push_back(_TempOp.front());
				_TempOp.pop();
			}
			_TempOp.pop();//����������
			ParentThesisFlag = false;
		}
		default:
			break;
		}
	}
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
	tree._Root = ParseFixedLenExpression(0, _tokens.size() - 1);
	return tree;
}


//һ�ɷ��ع��캯��������֮�����������
ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end, ExpressionSyntax left, SyntaxToken oper)
{

	int nextOpIdx = start + 1;
	ExpressionSyntax temp;
	printf("����Ѷ��壡\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken://�����֣���ô�ͽ��ϲ���Ϊ���ʽ
	{
		temp = ExpressionSyntax(_tokens[start]); PushTree(temp);
		printf("���ڵ���ʱֵΪ%d\n", temp._MainToken._NumberValue);
		left = ExpressionSyntax(left._MyIdx, oper, temp._MyIdx);
		PushTree(left);
		break;
	}

	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken://������֮�������ۣ������Ȳ����κδ���
	case SyntaxKind::OpenParenthesisToken:
	{
		for (int i = start; i < end; i++)
		{
			if (_tokens[i]._kind == SyntaxKind::CloseParenthesisToken)
			{
				temp = ParseFixedLenExpression(start, i);
				PushTree(temp);
				left = ExpressionSyntax(left._MyIdx, oper, temp._MyIdx);
				PushTree(left);
				nextOpIdx = i + 1;
				break;
			}
		}
		break;
	}
	default:break;
	}
	return NextExpression(nextOpIdx, end, left);

}

ExpressionSyntax Parser::ParseFixedLenExpression(int start, int end)
{
	int nextOpIdx = start + 1;
	ExpressionSyntax left;
	printf("���δ���壡\n");
	switch (_tokens[start]._kind)
	{
	case SyntaxKind::NumberToken:
	{
		left = ExpressionSyntax(_tokens[start]); 
		PushTree(left); 
		printf("����ֵΪ%d\n", left._MainToken._NumberValue);
		break;
	}
	case SyntaxKind::PlusToken:
	case SyntaxKind::MinusToken://������֮�������ۣ������Ȳ����κδ���
	case SyntaxKind::OpenParenthesisToken:
	{
		for (int i = start; i < end; i++)
		{
			if (_tokens[i]._kind == SyntaxKind::CloseParenthesisToken)
			{
				left = ParseFixedLenExpression(start + 1, i - 1);
				PushTree(left);
				nextOpIdx = i + 1;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return NextExpression(nextOpIdx, end,left);
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
