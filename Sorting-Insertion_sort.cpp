#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    int j,temp;
    for(int i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;a[j]>temp && j>=0;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
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
    
    //insertion short
    insertion_sort(a,n);
    
    cout<<"Sorted Array::";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    //4 3 2 10 12 1 5 6
}
