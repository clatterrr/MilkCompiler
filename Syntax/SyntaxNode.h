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
	SyntaxToken _MainToken;
};

class NumberExp : public ExpressionSyntax
{
public:
	NumberExp(SyntaxToken numberToken);
	~NumberExp();

	SyntaxKind _kind;
	SyntaxToken _NumberToken;
};


class BinaryExp : public ExpressionSyntax
{
public:
	BinaryExp(ExpressionSyntax left, SyntaxToken operatorToken,ExpressionSyntax right);
	~BinaryExp();
	SyntaxKind _kind;
	SyntaxToken _OperatorToken;
	ExpressionSyntax _Left;
	ExpressionSyntax _Right;
	
};
#endif // ! SYNTAXNODE_H


