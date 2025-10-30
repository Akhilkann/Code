#include<iostream>
using namespace std;
class base{
    public:
    base(){cout<<"base const"<<endl;}
    virtual void print(){cout<<"base"<<endl;}

};
class derived_a:virtual public base{
public:
    derived_a(){cout<<"derived_a const"<<endl;}
     void print(){cout<<"derived_a"<<endl;}
};
class derived_b:virtual public base{
public:
    derived_b(){cout<<"derived_b const"<<endl;}
     void print(){cout<<"derived_b"<<endl;}
};
class derived_c:public derived_a,public derived_b
{
    public:
    derived_c(){cout<<"derived_c const"<<endl;}
    void print()override{cout<<"derived_C"<<endl;}
};


using namespace std;

int main()
{
    // derived_c C;
    // C.print();
    // derived_a A;
    // A.print();
    base *p=new derived_c;
    p->print();
    return 0;
}