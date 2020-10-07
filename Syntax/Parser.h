#ifndef  PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <queue>
#include "SyntaxTree.h"
using namespace std;


	class Parser
	{
	public:
		Parser(string text);
		~Parser();

		vector<SyntaxToken> _tokens;
		SyntaxToken Peek(int offset);
		SyntaxToken NextToken();
		SyntaxTree ParseMe();
		StatementSyntax ParseEntireLineAsStatement();
		ExpressionSyntax ParseFixedLenExpression(int start, int end, ExpressionSyntax left, SyntaxToken oper);
		ExpressionSyntax ParseFixedLenExpression(int start, int end);
		ExpressionSyntax NextExpression(int nextOpIdx, int end, ExpressionSyntax left);
		void PushTree(ExpressionSyntax &exp);

		int _position;
		SyntaxToken Current;
		SyntaxTree tree;

	};

#endif // ! PARSER_H





