#include "SyntaxTree.h"
SyntaxTree::SyntaxTree(BasicExp root, SyntaxToken endOfFileToken)
{
  
    _Root = root;
    _EndOfFileToken = endOfFileToken;
}

SyntaxTree::~SyntaxTree()
{
}

