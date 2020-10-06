// acompiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "Evaluator.h"

void PrettyPrint(SyntaxNode node, string indent = " ")
{

}

int main()
{
    
    //Parser pa("! 0 + 3");
    //Parser pa("14 - 3 * 2");
   // Parser pa("(12 + 2)*6");
    Parser pa("11 + 16 - !33");
    for (int i = 0; i < pa._tokens.size(); i++)
    {
        if (pa._tokens[i]._kind == SyntaxKind::NumberToken)
        {
            printf("Number Value %d\n", pa._tokens[i]._NumberValue);
        }
        else
        {
            printf("text Value %s\n", pa._tokens[i]._text.c_str());
        }
    }

    SyntaxTree tree = pa.ParseMe();
    Evaluator eva(tree);
    printf("Final Result = %d",eva.Evaluate());
}