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
		leftValue = EvaluatorExpression(_Tree.ExpVec[node._MainExpIdx]);
		rightValue = EvaluatorExpression(_Tree.ExpVec[node._SubExpIdx]);
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
		return node._MainToken._NumberValue;
	}
	

	/*
	if (node->_Left._kind == SyntaxKind::NumberToken)
	{
		printf("left is a number Token,mainToken is %c\n",node->_MainToken._text.c_str());
	}
	else if (node->_Left._kind == SyntaxKind::BinaryExpression)
	{
		printf("left is a BinaryExpression ,mainToken is %c\n", node->_MainToken._text.c_str());
	}
	BinaryExp* bin; 
	NumberExp* num;
	int leftValue, rightValue;
	if ((bin = reinterpret_cast<BinaryExp*>(&node->_Left)) && (bin->_kind == SyntaxKind::BinaryExpression))
	{
		
		leftValue = EvaluatorExpression(bin);
	}
	else if ((num = reinterpret_cast<NumberExp*>(&node->_Left)) && (num->_kind == SyntaxKind::NumberToken))
	{
		leftValue = EvaluatorExpression(num);
	}
	if ((bin = reinterpret_cast<BinaryExp*>(&node->_Right)) && (bin->_kind == SyntaxKind::BinaryExpression))
	{
		rightValue = EvaluatorExpression(bin);
	}
	else if ((num = reinterpret_cast<NumberExp*>(&node->_Right)) && (num->_kind == SyntaxKind::NumberToken))
	{
		rightValue = EvaluatorExpression(num);
	}

	printf("LeftValue = %d,RightValue = %d\n", leftValue, rightValue);

		if (node->_OperatorToken._kind == SyntaxKind::PlusToken)
		{
			return leftValue + rightValue;
		}
		if (node->_OperatorToken._kind == SyntaxKind::MinusToken)
		{
			return leftValue - rightValue;
		}
		if (node->_OperatorToken._kind == SyntaxKind::StarToken)
		{
			return leftValue * rightValue;

		}
		if (node->_OperatorToken._kind == SyntaxKind::SlashToken)
		{
			return leftValue / rightValue;
		}
		*/
		return 0;
}

