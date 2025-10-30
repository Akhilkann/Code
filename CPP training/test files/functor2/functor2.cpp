

/*In C++, a function object (or functor) is any object that can be called as if it were a function. 
This is achieved by overloading the function call operator operator().*/

#include<iostream>


class multiplyby
{
    public:
    int value;
    multiplyby(int x):value(x){}  //initialized constructor 
    int operator() (int y){return value*y;}
};

int main()
{
    multiplyby MULTIPLYBY3(5);  //object created with value initialized by 5
    std::cout<<"5*3 = "<<MULTIPLYBY3(3);   //multiplying the value=5 with 3
    return 0;
}