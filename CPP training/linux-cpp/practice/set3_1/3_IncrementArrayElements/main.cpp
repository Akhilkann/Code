#include<iostream>
#include<string>
using namespace std;

int IncrementArray(int n,int *s);

int main()
{
    int Arr[]={1,2,3,4,5,6,7,8,9,0};
    int Status=IncrementArray(10,Arr);

    if(Status==0)
    {
        cout<<"{";
        for(int i=0;i<10;i++)
        {
            cout<<Arr[i];
            if((i+1)<10)
            {
                cout<<",";
            }
        }
        cout<<"}"<<endl;
    }

    return 0;
}

int IncrementArray(int n,int *s)
{
    for(int i=0;i<n;i++)
    {
        s[i]++;
    }
    return 0;
}