#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
char rev(char);
using namespace std;
int main()
{
    char exp[20];
    cout << "Enter an expressionn::";
    gets(exp);
    stack<char>s;
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
            s.push(exp[i]);
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if(s.empty())
            {
                cout<<"NOT a valid expression";
                exit(0);
            }
            if(rev(exp[i])==s.top())
            {
                s.pop();
            }

        }
    }
    if(s.empty())
        cout<<"valid Expression";
        else cout<<"not a valid expression";
    return 0;
}
char rev(char ch)
{
    if(ch==')')
        return '(';
    if(ch=='}')
        return '{';
    if(ch==']')
        return '[';
}

