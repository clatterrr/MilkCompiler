#include "SyntaxTree.h"
SyntaxTree::SyntaxTree()
{
}
SyntaxTree::SyntaxTree(StatementSyntax root, SyntaxToken endOfFileToken)
{
  
    _Root = root;
    _EndOfFileToken = endOfFileToken;
}

SyntaxTree::~SyntaxTree()
{
}

