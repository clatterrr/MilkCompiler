#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <vector>
#include"Symbol.h"
using namespace std;

//SymbolTableҲ��һ�����ϵĽڵ㣬����һ��SymbolTable����һ��SymbolTable�ĸ��ڵ㣬����������󣬵��ڵڶ���SymbolTable�Ҳ���ĳ�����ŵ�ʱ�򣬾�ȥ�丸�ڵ���
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



