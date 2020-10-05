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
    _MainToken = numberToken;
    _kind = SyntaxKind::NumberToken;
}

NumberExp::~NumberExp()
{
}

BinaryExp::BinaryExp(ExpressionSyntax left, SyntaxToken operatorToken, ExpressionSyntax right)
{
    _Left = left;
    _Right = right;
    _OperatorToken = operatorToken;
    _MainToken = operatorToken;
    _kind = SyntaxKind::BinaryExpression;

}

BinaryExp::~BinaryExp()
{
}

ExpressionSyntax::ExpressionSyntax()
{
}

ExpressionSyntax::~ExpressionSyntax()
{
}
