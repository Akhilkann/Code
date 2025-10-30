#include<iostream>
#include <bits/stdc++.h>

void Incrementvalue(int &a,int &b,auto fn)
{
    if(fn(a,b))
    {
        ++a;
        ++b;
    }
}


int main()
{


    int a=4,b=5;
    auto x=[a,b](){return a+b;};
    std::cout<<x()<<std::endl;

    std::cout<<"init values -> a="<<a<<" ,b="<<b<<std::endl;
    auto y=[&a,&b](int x){a+=x;b+=x;};
    y(2);
    std::cout<<"incremented values -> a="<<a<<" ,b="<<b<<std::endl;




    std::vector vect={2,4,6,7,2,1,0};

    std::sort(vect.begin(),vect.end(),[](int a,int b){return a>b;});

    for(auto i=vect.begin();i!=vect.end();i++)
    {
        std::cout<<*i<<std::endl;
    }

    /*Created a functio Incrementvalue and 
    calling the function to increment the values when both are equal w and u 
    lambda function is used as the parameter when calling the function*/

    int w=3,u=2;
    Incrementvalue(w,u,[](int a, int b){return a==b;});
    std::cout<<"w="<<w<<" u="<<u<<std::endl;

    /*Same Incrementvalue is called to increment the values when w>u
    lambda function in the arqument list is updated to check whether w>u*/

    Incrementvalue(w,u,[](int a, int b){return a>b;});
    std::cout<<"w="<<w<<" u="<<u<<std::endl;
    return 0;
}