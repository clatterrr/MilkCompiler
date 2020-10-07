#include "SyntaxNode.h"

SyntaxNode::SyntaxNode()
{
}

SyntaxNode::~SyntaxNode()
{
}


ExpressionSyntax::ExpressionSyntax()
{
}

ExpressionSyntax::ExpressionSyntax(SyntaxToken numberToken)
{
    _Token0 = numberToken;
    if (numberToken._kind == SyntaxKind::NumberToken)
    {
        _MyKind = SyntaxKind::NumberToken;
    }
    else
    {
        _MyKind = SyntaxKind::IdentifierToken;
    }
    
}

ExpressionSyntax::ExpressionSyntax(SyntaxToken UnaryOp, int right)
{
    _Token0 = UnaryOp;
    _ExpIdx0 = right;
    _MyKind = SyntaxKind::UnaryExpression;
}

ExpressionSyntax::ExpressionSyntax(int left, SyntaxToken operatorToken, int right)
{
    _ExpIdx0 = left;
    _Token0 = operatorToken;
    _ExpIdx1 = right;
    _MyKind = SyntaxKind::BinaryExpression;
}

ExpressionSyntax::ExpressionSyntax(SyntaxToken openThesisToken, int expression, SyntaxToken closeThesisToken)
{
    _Token0 = openThesisToken;
    _ExpIdx0 = expression;
    _Token1 = closeThesisToken;
    _MyKind = SyntaxKind::ThesisExpression;
}

ExpressionSyntax::~ExpressionSyntax()
{
}

StatementSyntax::StatementSyntax()
{
}

StatementSyntax::~StatementSyntax()
{
}

StatementSyntax::StatementSyntax(SyntaxToken type, SyntaxToken identifier, SyntaxToken equal, int expIdx)
{
    _MyKind = SyntaxKind::VariableDeclaration;
    _Token0 = type;
    _Token1 = identifier;
    _Token2 = equal;
    _ExpIdx0 = expIdx;
}

StatementSyntax::StatementSyntax(SyntaxToken identifier, SyntaxToken equal, int expIdx)
{
    _MyKind = SyntaxKind::AssignStatement;
    _Token0 = identifier;
    _Token1 = equal;
    _ExpIdx0 = expIdx;

}

StatementSyntax::StatementSyntax(SyntaxToken IfKeyword, int expIdx)
{
    if (IfKeyword._kind == SyntaxKind::IfKeyWord)
    {
        _MyKind = SyntaxKind::IfStatement;
    }
    else if (IfKeyword._kind == SyntaxKind::PrintKeyWord)
    {
        _MyKind = SyntaxKind::PrintStatement;
    }
    _Token0 = IfKeyword;
    _ExpIdx0 = expIdx;
}
