


#ifndef  SYNTAXTREE_H
#define SYNTAXTREE_H
#include <vector>
#include "Lexer.h"

	class SyntaxTree
	{
	public:
		SyntaxTree();
		SyntaxTree(ExpressionSyntax root, SyntaxToken endOfFileToken);
		~SyntaxTree();
		ExpressionSyntax _Root;
		SyntaxToken _EndOfFileToken;
		vector<ExpressionSyntax> ExpVec;
	};



#endif // !1



