#include<iostream>
using namespace std;

void LargestOfArray(int *ptr,int size,int &b);

int main()
{
    int n=0;
    int Result;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"\nEnter the elements"<<endl;
    
    int *ptr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>ptr[i];
    }
    void (*FnPtr)(int *,int,int &);

    FnPtr=LargestOfArray;
    FnPtr(ptr,n,Result);

    cout<<"Largest is "<<Result<<endl; 
    
    return 0;
}

void LargestOfArray(int *ptr,int size,int &b)
{
    b=0;
    for(int i=0;i<size;i++)
    {
        if(ptr[i]>b)
        {
            b=ptr[i];
        }
    }
}