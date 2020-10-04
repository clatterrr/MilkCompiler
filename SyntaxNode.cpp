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
    _kind = NumberToken;
}

NumberExp::~NumberExp()
{
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
