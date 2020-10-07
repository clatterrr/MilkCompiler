#ifndef  SYNTAXNODE_H
#define SYNTAXNODE_H
#include "SyntaxToken.h"

class SyntaxNode
{
public:
	SyntaxNode();
	~SyntaxNode();

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
	SyntaxToken _Token0;
	SyntaxToken _Token1;
	//傻逼链表次次报错，老子不用也罢
	//ExpressionSyntax* _MainExpression;
	int _ExpIdx0;
	SyntaxKind _ExpKind0;
	//ExpressionSyntax* _SubExpression;
	int _ExpIdx1;
	SyntaxKind _ExpKind1;
	int Value;
};

class StatementSyntax :public SyntaxNode
{
public:
	StatementSyntax();
	~StatementSyntax();
	//VariableDeclaration _Token0 _Token1 _Token2 _ExpIdx0
	StatementSyntax(SyntaxToken type, SyntaxToken identifier, SyntaxToken equal, int expIdx);
	//AssginStateMent _Token0 _Token1 _ExpIdx0
	StatementSyntax(SyntaxToken identifier, SyntaxToken equal, int expIdx);
	//If print _Token0 _ExpIdx0
	StatementSyntax(SyntaxToken IfKeyword, int expIdx);

	SyntaxKind _MyKind;
	int _MyIdx;
	SyntaxToken _Token0;
	SyntaxToken _Token1;
	SyntaxToken _Token2;
	int _ExpIdx0;
};
#endif // ! SYNTAXNODE_H


