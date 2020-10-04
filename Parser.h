#ifndef  PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Lexer.h"
using namespace std;

class Parser
{
	Parser(string text);
	~Parser();

	vector<SyntaxToken> _tokens;
	SyntaxToken Peek(int offset);

	int _position;

};


#endif // ! PARSER_H





