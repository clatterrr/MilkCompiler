#ifndef  PARSER_H
#define PARSER_H

#include <vector>
#include <string>
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
		BasicExp ParseExpression();
		BasicExp ParsePrimaryExpression();
		SyntaxToken Match(SyntaxKind kind);

		int _position;
		SyntaxToken Current;

	};

#endif // ! PARSER_H





