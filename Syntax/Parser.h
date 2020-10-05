#ifndef  PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Lexer.h"
using namespace std;

class Parser
{
public:
	Parser(string text);
	~Parser();

	vector<SyntaxToken> _tokens;
	SyntaxToken Peek(int offset);
	SyntaxToken NextToken();
	ExpressionSyntax Parse();
	ExpressionSyntax ParsePrimaryExpression();
	SyntaxToken Match(SyntaxKind kind);

	int _position;
	SyntaxToken Current;

};


#endif // ! PARSER_H





