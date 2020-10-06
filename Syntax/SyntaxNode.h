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
	//SingleNumberExpression _MainToken
	ExpressionSyntax(SyntaxToken numberToken);
	//_MainToken _MainExp
	ExpressionSyntax(SyntaxToken UnaryOp, int right);
	//BinaryExpression   _MianExp _MainToken _SubExp
	ExpressionSyntax(int left, SyntaxToken operatorToken, int right);
	ExpressionSyntax(SyntaxToken openThesisToken, int expression, SyntaxToken closeThesisToken);
	~ExpressionSyntax();

	SyntaxKind _MyKind;
	int _MyIdx;
	SyntaxToken _MainToken;
	SyntaxToken _SubToken;
	//傻逼链表次次报错，老子不用也罢
	//ExpressionSyntax* _MainExpression;
	int _MainExpIdx;
	SyntaxKind _MainExpKind;
	//ExpressionSyntax* _SubExpression;
	int _SubExpIdx;
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


