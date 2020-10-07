


#ifndef  SYNTAXTREE_H
#define SYNTAXTREE_H
#include <vector>
#include "Lexer.h"

	class SyntaxTree
	{
	public:
		SyntaxTree();
		SyntaxTree(StatementSyntax root, SyntaxToken endOfFileToken);
		~SyntaxTree();
		StatementSyntax _Root;
		SyntaxToken _EndOfFileToken;
		vector<ExpressionSyntax> ExpVec;
		vector<StatementSyntax> StateVec;
	};



#endif // !1



