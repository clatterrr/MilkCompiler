#include "SyntaxNode.h"

SyntaxNode::SyntaxNode()
{
}

SyntaxNode::~SyntaxNode()
{
}

SyntaxKind SyntaxNode::GetKind()
{
    return SyntaxKind();
}

NumberExp::NumberExp(SyntaxToken numberToken)
{
    _NumberToken = numberToken;
}

NumberExp::~NumberExp()
{
}

BinaryExp::BinaryExp()
{
}

BinaryExp::BinaryExp(ExpressionSyntax left, SyntaxToken operatorToken, ExpressionSyntax right)
{
    _Left = left;
    _Right = right;
    _OperatorToken = operatorToken;

}

void BinaryExp::CreateBinaryExp(ExpressionSyntax left, SyntaxToken operatorToken, ExpressionSyntax right)
{
    _Left = left;
    _Right = right;
    _OperatorToken = operatorToken;
}

BinaryExp::~BinaryExp()
{
}

ExpressionSyntax::ExpressionSyntax()
{
    _MyKind = SyntaxKind::UnDefined;
}

ExpressionSyntax::~ExpressionSyntax()
{
}

ThesisExp::ThesisExp(SyntaxToken openThesisToken, ExpressionSyntax expression, SyntaxToken closeThesisToken)
{
    _OpenThesisToken = openThesisToken;
    _Expression = expression;
    _CloseThesisToken = closeThesisToken;
}

ThesisExp::~ThesisExp()
{
}


ExpressionSyntax::ExpressionSyntax(SyntaxToken numberToken)
{
    _MainToken = numberToken;
    _MyKind = SyntaxKind::NumberToken;
}

ExpressionSyntax::ExpressionSyntax(SyntaxToken UnaryOp, int right)
{
    _MainToken = UnaryOp;
    _MainExpIdx = right;
    _MyKind = SyntaxKind::UnaryExpression;
}

ExpressionSyntax::ExpressionSyntax(int left, SyntaxToken operatorToken, int right)
{
    _MainExpIdx = left;
    _MainToken = operatorToken;
    _SubExpIdx = right;
    _MyKind = SyntaxKind::BinaryExpression;
}

ExpressionSyntax::ExpressionSyntax(SyntaxToken openThesisToken, int expression, SyntaxToken closeThesisToken)
{
    _MainToken = openThesisToken;
    _MainExpIdx = expression;
    _SubToken = closeThesisToken;
    _MyKind = SyntaxKind::ThesisExpression;
}

