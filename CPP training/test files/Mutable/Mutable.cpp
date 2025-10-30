#include<iostream>

class ClassA{

    public:
    int x;
    mutable int y;  //mutable member
    static int st;  
    ClassA():x(10),y(2){}
};

int ClassA::st=9;  //static member initialization

int main()
{
    const ClassA obj1;
    ClassA obj2;
    //obj1.x=1;  //unable to modify const class member
    obj1.y=7;   //able to modify mutable member inside const class
    
    obj1.st=10;
    std::cout<<obj1.x<<"  "<<obj1.y<<" "<<obj1.st<<ClassA::st<<std::endl;
    std::cout<<obj2.x<<"  "<<obj2.y<<" "<<obj2.st<<ClassA::st<<std::endl;

    return 0;
}