#include<iostream>
using namespace std;
long long factorial(int n);

int main()
{
    int input = 0;
    long long output=1;
    cout<<"Enter a number"<<endl;
    cin>>input;
    output=factorial(input);
    cout<<"factorial of "<<input<<" is   "<<output<<endl;

    return 0;
}

long long factorial(int n)
{
    long long factorial = 1;
    for(int i=1;i<=n;i++)
    {
        factorial=factorial*i;
    }
    return factorial;
}