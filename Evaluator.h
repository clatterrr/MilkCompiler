#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Syntax\Parser.h"
#include "Symbol\SymbolTable.h"

//Global Evaluator used for handle SymbolTable Tee
class Evaluator
{
public:
	Evaluator();
	Evaluator(SyntaxTree tree);
	~Evaluator();
	ExpressionSyntax _Root;
	SyntaxTree _Tree;
	void Evaluate(SyntaxTree tree);
	vector<SymbolTable> _STTVec;
	int EvaluatorExpression(ExpressionSyntax node);
	void EvaluatorStatement(StatementSyntax node);
	bool _ShouldOutput;
	int _ResultOutput;
	int _CurrentSTT;
};

#endif // !EVALUATOR_H



