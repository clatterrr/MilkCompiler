#include "Evaluator.h"

Evaluator::Evaluator(BasicExp root)
{
	_Root = root;
	
}

Evaluator::~Evaluator()
{
}

int Evaluator::Evaluate()
{
	return 0;
}

int Evaluator::EvaluatorExpression(BasicExp node)
{
	int leftValue, rightValue;
	printf("now main token is %s\n", node._MainToken._text.c_str());
	if (node._Kind == SyntaxKind::BinaryExpression)
	{
		leftValue = EvaluatorExpression(BasicExp(node._MainExpression, node._MainExpKind));
	}
	else if (node._Kind == SyntaxKind::NumberToken)
	{
		printf("now value = %d\n", node._MainToken._NumberValue);
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

