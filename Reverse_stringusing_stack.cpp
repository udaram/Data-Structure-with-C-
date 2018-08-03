#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;
void Reverse(char *,int);
int main()
{
    char s[20];
    cout<<"\nEnter name::";
    gets(s);
    Reverse(s,strlen(s));
    cout<<s;
    return 0;
}
void Reverse(char *c,int n)
{
    stack<char>s;
    int i;
    for(i=0;i<n;i++)
        s.push(c[i]);
    for(i=0;i<n;i++)
    {
        c[i]=s.top();
        s.pop();
    }
}


