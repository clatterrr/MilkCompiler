#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Syntax\Parser.h"
class Evaluator
{
public:
	Evaluator(SyntaxTree tree);
	~Evaluator();
	ExpressionSyntax _Root;
	SyntaxTree _Tree;
	int Evaluate();

	int EvaluatorExpression(ExpressionSyntax node);
};

#endif // !EVALUATOR_H



