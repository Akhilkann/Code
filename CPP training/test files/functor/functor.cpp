/*In C++, a functor, also known as a function object, 
is an object that can be invoked or "called" as if it were a function. 
This is achieved by overloading the function call operator, operator(), for a class or struct*/


#include<iostream>
#include <bits/stdc++.h>
//#define OPERATOROVERLOADING
#define FUNCTORR

#ifdef OPERATOROVERLOADING
class A{
    int var;
    public:
    int operator ()(int a, int b){ return a+b;}
    int operator ++(){return ++var;}  //pre increment
    int operator ++(int){return var++;} //post increment

    A(int a):var(a){}
};
#endif

class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};

struct greater{

    bool operator ()(int L,int R){
        return L>R;
    }
};

int main()
{
#ifdef OPERATOROVERLOADING
    A objA(10);
    int sum = objA(2,3);
    int increment =++objA;
    std::cout<<sum<<std::endl;
    std::cout<<"pre increment="<<increment<<std::endl;

    std::cout<<"post increment  ="<<objA++<<std::endl;
#endif 
#ifdef FUNCTORR

    

    
    // int  arr[]={2,54,67,3,43};
    // std::transform(arr,arr+5,arr,increment(3));    /*is the same as writing below two lines, Creating object of increment
    //                                                     increment obj(to_add); 
    //                                                      Calling () on object
    //                                                 transform(arr, arr+n, arr, obj); */
    // for(auto i=0;i<5;i++)
    // {
    //     std::cout<<arr[i]<<" "<<std::endl;
    // }


    std::vector vect={2,54,67,3,43};
    std::sort(vect.begin(),vect.end(),greater());
    for(auto i=vect.begin();i!=vect.end();i++)
    {
        std::cout<<*i<<std::endl;
    }

#endif
    return 0;
}