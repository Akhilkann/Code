#include<iostream>
using namespace std;
class test
{
    
    public:
    int x;
    test(){}
    test(int a):x(a){}
    test operator+(const test& a){ return test(x+a.x);}
    test operator-(const test& b){ return test(x-b.x);}
};
int main()
{
    test A,B(10),C(5);
    A=B+C;
    cout<<A.x<<endl;
    A=B-C;
    cout<<A.x<<endl;

    return 0;
}