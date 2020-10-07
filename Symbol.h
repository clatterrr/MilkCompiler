#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
using namespace std;
#include ""

class Symbol
{
	Symbol();
	~Symbol();

	string _Name;
	SyntaxKind _Type;
	int _NumberValue;
	int Scope;
};

class VariableSymbol
{

};

#endif // !SYMBOL_H



