#include<iostream>

class A{

    int a;
    public:
    A(int a):a(a){};

    void hello(){std::cout<<"helloo"<<std::endl;}
    friend class B;
};

class B{
    public:
    void display(A& x){std::cout<<x.a<<std::endl; x.hello();}
};

int main()
{
    A objA(10);
    B objB;
    objB.display(objA);
    return 0;
}