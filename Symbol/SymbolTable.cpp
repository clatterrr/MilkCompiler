#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	_ParentIdx = -1;
}

SymbolTable::~SymbolTable()
{
}

Symbol SymbolTable::FindSymbolWithText(string text)
{
	for (int i = 0; i < _SymbolVec.size(); i++)
	{
		if (_SymbolVec[i]._Name == text)
		{
			return _SymbolVec[i];
		}
	}
}

void SymbolTable::AddSymbol(Symbol symbol)
{
	_SymbolVec.push_back(symbol);
}

void SymbolTable::AddSymbol(string name, SyntaxKind kind, int value)
{
	Symbol symbol(name, kind, value);
	_SymbolVec.push_back(symbol);
}

void SymbolTable::EditSymbolValue(string text, int numbervalue)
{
	for (int i = 0; i < _SymbolVec.size() ; i++)
	{
		if (_SymbolVec[i]._Name == text)
		{
			_SymbolVec[i]._NumberValue = numbervalue;
			return;
		}
	}
}
