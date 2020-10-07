#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <vector>
#include"Symbol.h"
using namespace std;

//SymbolTable也是一个树上的节点，比如一个SymbolTable是另一个SymbolTable的父节点，包含的域更大，当在第二个SymbolTable找不到某个符号的时候，就去其父节点找
class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();

	//ReadOnly,  Edit has no effect
	Symbol FindSymbolWithText(string text);
	void AddSymbol(Symbol symbol);
	void AddSymbol(string name, SyntaxKind kind, int value);
	void EditSymbolValue(string text, int numbervalue);

	vector<Symbol> _SymbolVec;
	int _MyIdx;
	int _ParentIdx;
};



#endif // !SYMBOLTABLE_H



