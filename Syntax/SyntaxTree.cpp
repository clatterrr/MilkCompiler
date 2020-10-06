#include "SyntaxTree.h"
SyntaxTree::SyntaxTree()
{
}
SyntaxTree::SyntaxTree(ExpressionSyntax root, SyntaxToken endOfFileToken)
{
  
    _Root = root;
    _EndOfFileToken = endOfFileToken;
}

SyntaxTree::~SyntaxTree()
{
}

