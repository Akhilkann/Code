/*
->A copy constructor is a special constructor that creates a new object as a copy of an
  existing object of the same class. 
->A move constructor in C++ is a special type of constructor that facilitates the transfer 
  of ownership of resources from one object to another without performing a deep copy.
*/


#include<iostream>
using namespace std;

class Test
{
    int a;
    int *p;
    public:
    int q;
    Test();
    Test(const Test& x); //copy constructor
    Test(Test&& x); //Move construcor
    ~Test();
    void display();

};
Test::Test(): a(10),q(20),p(new int)
{ cout<<"Const1"<<endl; }

/*copy constructor definition*/
Test::Test(const Test& x): a(x.a),p(x.p)
{ cout<<"Cpconst"<<endl;}

/*Move constructoe definition*/
Test::Test(Test&& x):a(x.a),p(x.p),q(x.q)
{ 
    cout<<"MovCOnst"<<endl;
    x.p=nullptr;
}

Test::~Test()
{cout<<"Destr"<<endl;}

void Test::display()
{
    cout<<"a="<<a<<" *p="<<*p<<" q="<<q<<" &a=  "<<&a<<" p=  "<<p<<endl;
    *p=*p+1;
}

void tstArg(Test a)
{  
    a.display();
}

int main()
{
     Test A;
     A.display();
     Test b=A;   //call copy constructor -object is initialized with anther object of same class
    
     b.q=25;
     b.display();

     tstArg(A);   //call copy construcor-  object as argument
     A.display();

     /*----Move constructor------*/
     Test C =move(A);
     C.display();


    return 0;
}