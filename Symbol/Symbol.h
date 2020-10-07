#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
using namespace std;

#include "../Syntax/SyntaxKind.h"

class Symbol
{
public:
	Symbol();
	Symbol(string name, SyntaxKind kind, int value);
	~Symbol();

	string _Name;
	SyntaxKind _Kind;
	int _NumberValue;
};

class VariableSymbol
{

};

#endif // !SYMBOL_H



