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


};


int main()
{
    CLASS1 <int>obj1(10);
    CLASS1<int> obj2(30);
    obj1.print();
    // unique_ptr<CLASS1<int>> P1(new CLASS1(20));
    // cout<<P1.get()<<endl;
    // P1->print();
    unique_ptr<CLASS1<int>> P2=/*move(P1);//*/make_unique<CLASS1<int>>(obj2);
    unique_ptr<CLASS1<int>> P4=move(P2);//make_unique<CLASS1<int>>(obj2);
    CLASS1 <int>*P3=&obj1;
   // P2->print();
    P4->print();
    cout<<P4.get()<<endl;
    //P2.release(); //if P2 not released manually compiler try to free the address which is already killed (obj2) at the end of the main pgm
    P4.release();
    P3->print();
    
    cout<<"end of program"<<endl;
    return 0;
}