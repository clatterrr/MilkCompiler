#include "Symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(string name, SyntaxKind kind, int value)
{
	_Name = name;
	_Kind = kind;
	_NumberValue = value;
}

Symbol::~Symbol()
{
}
