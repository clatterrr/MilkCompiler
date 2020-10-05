#ifndef  SYNTAXNODE_H
#define SYNTAXNODE_H
#include "SyntaxToken.h"

class SyntaxNode
{
public:
	SyntaxNode();
	~SyntaxNode();

	virtual SyntaxKind GetKind();
};

class ExpressionSyntax : public SyntaxNode
{
public:
	ExpressionSyntax();
	~ExpressionSyntax();

	SyntaxKind _Kind;
};

class BasicExp:public ExpressionSyntax
{
public:
	BasicExp();//default
	BasicExp(ExpressionSyntax aExp, SyntaxKind kind);
	BasicExp(SyntaxToken numberToken);
	BasicExp(ExpressionSyntax left, SyntaxKind leftkind, SyntaxToken operatorToken, ExpressionSyntax right, SyntaxKind rightkind);
	BasicExp(SyntaxToken openThesisToken, ExpressionSyntax expression, SyntaxToken closeThesisToken);
	~BasicExp();

	SyntaxToken _MainToken;
	SyntaxToken _SubToken;
	ExpressionSyntax _MainExpression;
	SyntaxKind _MainExpKind;
	ExpressionSyntax _SubExpression;
	SyntaxKind _SubExpKind;
	int Value;
};

//单个数字
class NumberExp : public ExpressionSyntax
{
public:
	NumberExp(SyntaxToken numberToken);
	~NumberExp();

	SyntaxToken _NumberToken;
};

//加减乘除
class BinaryExp : public ExpressionSyntax
{
public:
	BinaryExp();
	BinaryExp(ExpressionSyntax left, SyntaxToken operatorToken,ExpressionSyntax right);
	void CreateBinaryExp(ExpressionSyntax left, SyntaxToken operatorToken, ExpressionSyntax right);
	~BinaryExp();
	ExpressionSyntax _Left;
	SyntaxToken _OperatorToken;
	ExpressionSyntax _Right;
	
};

//括号
class ThesisExp :public ExpressionSyntax
{
public:
	ThesisExp(SyntaxToken openThesisToken, ExpressionSyntax expression, SyntaxToken closeThesisToken);
	~ThesisExp();
	SyntaxToken _OpenThesisToken;
	ExpressionSyntax _Expression;
	SyntaxToken _CloseThesisToken;
};
#endif // ! SYNTAXNODE_H


