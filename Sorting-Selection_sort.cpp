#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}
void selection_sort(int a[],int n)
{
    int j,min_index;
    for(int i=0;i<n;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index = j ;
            }
        }
        swap(&a[i],&a[min_index]);
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
    
    //selection short
    selection_sort(a,n);
    cout<<"Sorted Array::";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    //4 3 2 10 12 1 5 6
}
