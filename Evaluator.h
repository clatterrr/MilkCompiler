#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Syntax\Parser.h"
class Evaluator
{
public:
	Evaluator(BasicExp root);
	~Evaluator();
	BasicExp _Root;
	int Evaluate();

	int EvaluatorExpression(BasicExp node);
};

#endif // !EVALUATOR_H



