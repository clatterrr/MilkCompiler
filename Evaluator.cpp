#include "Evaluator.h"
#include <iostream>

Evaluator::Evaluator()
{
	SymbolTable aSymbolTable;
	aSymbolTable._MyIdx = _STTVec.size();
	_STTVec.push_back(aSymbolTable);
	_CurrentSTT = 0;
}

Evaluator::Evaluator(SyntaxTree tree)
{
	_Tree = tree;
	
}

Evaluator::~Evaluator()
{
}

void Evaluator::Evaluate(SyntaxTree tree)
{
	_Tree = tree;
	_ShouldOutput = false;
	 EvaluatorStatement(_Tree._Root);
}

int Evaluator::EvaluatorExpression(ExpressionSyntax node)
{
	int leftValue, rightValue;
	if (node._MyKind == SyntaxKind::BinaryExpression)
	{
		printf("二元表达式！\n");
		leftValue = EvaluatorExpression(_Tree.ExpVec[node._ExpIdx0]);
		rightValue = EvaluatorExpression(_Tree.ExpVec[node._ExpIdx1]);
		printf("左值为%d，右值为%d\n",leftValue,rightValue);
		switch (node._Token0._kind)
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
		printf("数字！%d\n", node._Token0._NumberValue);

		return node._Token0._NumberValue;
	}
	else if (node._MyKind == SyntaxKind::UnaryExpression)
	{
		switch (node._Token0._kind)
		{
		case SyntaxKind::PlusToken:return EvaluatorExpression(_Tree.ExpVec[node._ExpIdx0]);
		case SyntaxKind::MinusToken:return -EvaluatorExpression(_Tree.ExpVec[node._ExpIdx0]);
		case SyntaxKind::NOTToken:
		{
			int result = EvaluatorExpression(_Tree.ExpVec[node._ExpIdx0]);
			return !result;
		}
		default:return 0;
			break;
		}
	}
		return 0;
}

void Evaluator::EvaluatorStatement(StatementSyntax node)
{
	switch (node._MyKind)
	{
	case SyntaxKind::VariableDeclaration:
	{
		//把变量添加进符号表，默认类型是int
		_STTVec[_CurrentSTT].AddSymbol(node._Token1._text,node._Token0._kind,0);
		int result = EvaluatorExpression(_Tree.ExpVec[node._ExpIdx0]);
		_STTVec[_CurrentSTT].EditSymbolValue(node._Token1._text, result);
		printf("已经新建变量%s，其值是%d\n", node._Token1._text.c_str(), result);
		break;
	}
	case SyntaxKind::PrintStatement:
	{
		_ShouldOutput = true;
		_ResultOutput =  _STTVec[_CurrentSTT].FindSymbolWithText(_Tree.ExpVec[node._ExpIdx0]._Token0._text)._NumberValue;
		printf("需要输出变量%s，其值是%d\n", _Tree.ExpVec[node._ExpIdx0]._Token0._text.c_str(), _ResultOutput);
		break;
	}
	case SyntaxKind::AssignStatement:
	case SyntaxKind::IfStatement:
	default:
		break;
	}
}

