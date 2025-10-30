#include<iostream>
#include<memory>

using namespace std;

template<typename A>
class CLASS1{
    A *ptr;
    public:
    CLASS1(){}
    CLASS1(A x):ptr(new A){ *ptr=x;cout<<"const"<<endl;}
    CLASS1(const CLASS1& a):ptr(a.ptr){cout<<"copy"<<endl;}
    CLASS1(CLASS1 && a):ptr(nullptr){cout<<"move"<<endl; ptr=a.ptr;a.ptr=nullptr;}
    ~CLASS1(){delete ptr;cout<<"dest"<<endl;}

    void print(){cout<<ptr<<"   "<<*ptr<<endl;}
    void incremnt(){(*ptr)++;}


};


int main()
{
    CLASS1 <int>obj1(10);

    shared_ptr<CLASS1<int>> P1/*=make_shared<CLASS1<int>>(obj1);/*/(new CLASS1(10));
    cout<<P1.use_count()<<endl;
    shared_ptr<CLASS1<int>> P2=P1;
    cout<<P1.use_count()<<endl;
    shared_ptr<CLASS1<int>> P3=P2;
    cout<<P1.use_count()<<endl;

    P1->print();
    P2->print();
    P3->print();

    P1->incremnt();
    cout<<"after incrementing"<<endl;
    P1->print();
    P2->print();
    P3->print();

    //P1.reset();
    //cout<<P2.use_count()<<endl;
    //P2.reset();
    // cout<<P3.use_count()<<endl;
    //P3.reset();
    cout<<P3.use_count()<<endl;
    //P1->print();
    //P2->print();
    //P3->print();
    cout<<"end of program"<<endl;
    return 0;
}