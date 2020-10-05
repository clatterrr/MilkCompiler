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

BasicExp::BasicExp()
{
}

BasicExp::BasicExp(ExpressionSyntax aExp, SyntaxKind kind)
{
    _MainExpression = aExp;
    _Kind = kind;
}

BasicExp::BasicExp(SyntaxToken numberToken)
{
    _MainToken = numberToken;
    _Kind = SyntaxKind::NumberToken;
}

BasicExp::BasicExp(ExpressionSyntax left, SyntaxKind leftkind, SyntaxToken operatorToken, ExpressionSyntax right,SyntaxKind rightkind)
{
    _MainExpression = left;
    _MainExpKind = leftkind;
    _MainToken = operatorToken;
    _SubExpression = right;
    _SubExpKind = rightkind;
    _Kind = SyntaxKind::BinaryExpression;
}

BasicExp::BasicExp(SyntaxToken openThesisToken, ExpressionSyntax expression, SyntaxToken closeThesisToken)
{
    _MainToken = openThesisToken;
    _MainExpression = expression;
    _SubToken = closeThesisToken;
    _Kind = SyntaxKind::ThesisExpression;
}

BasicExp::~BasicExp()
{
}
