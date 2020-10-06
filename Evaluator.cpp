#include "Evaluator.h"
#include <iostream>

Evaluator::Evaluator(SyntaxTree tree)
{
	_Tree = tree;
	
}

Evaluator::~Evaluator()
{
}

int Evaluator::Evaluate()
{
	return EvaluatorExpression(_Tree._Root);
}

int Evaluator::EvaluatorExpression(ExpressionSyntax node)
{
	int leftValue, rightValue;
	if (node._MyKind == SyntaxKind::BinaryExpression)
	{
		printf("��Ԫ���ʽ��\n");
		leftValue = EvaluatorExpression(_Tree.ExpVec[node._MainExpIdx]);
		rightValue = EvaluatorExpression(_Tree.ExpVec[node._SubExpIdx]);
		printf("��ֵΪ%d����ֵΪ%d\n",leftValue,rightValue);
		switch (node._MainToken._kind)
		{
		case SyntaxKind::PlusToken:return leftValue + rightValue;
		case SyntaxKind::MinusToken:return leftValue - rightValue;
		case SyntaxKind::StarToken:return leftValue * rightValue;
		case SyntaxKind::SlashToken:return leftValue / rightValue;
		default:return 0;
			break;
		}
	}
	else if(node._MyKind == SyntaxKind::NumberToken)
	{
		printf("���֣�%d\n", node._MainToken._NumberValue);

		return node._MainToken._NumberValue;
	}
		return 0;
}

