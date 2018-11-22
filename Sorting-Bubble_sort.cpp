#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}
void bubble_sort(int a[],int n)
{
    int j,min_index;
    for(int i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(&a[j],&a[j+1]);
            }
        }
        
    }
}
int main()
{
    int n;
    cout<<"Size of Array::";
    cin>>n;
    int a[n];
    cout<<"Enter Sequence::";
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    //bubble short
    bubble_sort(a,n);
    cout<<"Sorted Array::";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    
}
