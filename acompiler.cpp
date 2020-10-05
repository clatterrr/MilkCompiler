// acompiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "Evaluator.h"

void PrettyPrint(SyntaxNode node, string indent = " ")
{

}

int main()
{
    Parser pa("14 + 2 - 3");//这时候就把5个字符全部存为SynatexNode数组了，忽视掉了空格
    SyntaxTree tree = pa.ParseMe();
    printf("exp is %s\n", tree._Root._MainToken._text.c_str());
    Evaluator eva(tree._Root);
   printf("%d\n",eva.EvaluatorExpression(tree._Root));
    PrettyPrint(tree._Root);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
