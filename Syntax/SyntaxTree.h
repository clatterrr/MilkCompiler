


#ifndef  SYNTAXTREE_H
#define SYNTAXTREE_H
#include "Lexer.h"

	class SyntaxTree
	{
	public:
		SyntaxTree(BasicExp root, SyntaxToken endOfFileToken);
		~SyntaxTree();
		BasicExp _Root;
		SyntaxToken _EndOfFileToken;
	};



#endif // !1



