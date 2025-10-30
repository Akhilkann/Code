#include<iostream>
namespace S1{
inline int add(int a,int b)
{
    return a+b;
}
inline namespace S2{    //if using inline namespace then using namespace S1 is enough to call the function inside namespace S2
void updateValuePtr1(int*& p)
{
    int* q = new int(500);
    p = q;
    *q = *q + 1;
}
}
}

int main()
{
    using namespace S1;
    int res=add(10,4);
    std::cout<<res<<std::endl;

    int *pt=new int(10);
    using namespace S2;   //if namespace S1 is not useing as above then use- using namespace S1::S2 
    updateValuePtr1(pt);
    std::cout<<"*pt = "<<*pt<<std::endl;


    

}