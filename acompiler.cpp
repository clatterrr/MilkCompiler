// acompiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "Evaluator.h"


int main()
{
    vector<string> str;
    str.resize(2);
    str[0] = "int a = 10 + 5";
    str[1] = "print(a)";

    Evaluator GlobalEvluator;


    int LineIdx = 0;
    while (true)
    {
        if (LineIdx >= str.size())
            break;

        Parser pa(str[LineIdx]);//现在这个Parser先放在SyntaxTree的外面，不知道Minsk的为什么要放外面

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
        GlobalEvluator.Evaluate(tree);
        if (GlobalEvluator._ShouldOutput)
        {
            printf("MilkCompiler OutPut : %d\n", GlobalEvluator._ResultOutput);
        }
        LineIdx++;
   
    }

    
}