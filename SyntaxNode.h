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
	BinaryExp();
	~BinaryExp();
};
#endif // ! SYNTAXNODE_H


