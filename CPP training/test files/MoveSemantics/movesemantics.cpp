#include<iostream>

class A
{
    int *ptr;
    int a;
    public:
    A(){}
    A(int x):ptr(new int){*ptr=x; std::cout<<"copy "<<ptr<<std::endl;}
    A(A&& x):ptr(x.ptr){x.ptr=nullptr;std::cout<<"move "<<ptr<<std::endl;}
    void read(){std::cout<<"a= "<<*ptr<<std::endl;}
};

int main()
{
    A obj(10);
    A obj2=std::move(obj);
    obj2.read();
    return 0;
}