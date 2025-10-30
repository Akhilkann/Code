#include<iostream>
#include<string>

int main()
{
    std::string x,u;
    x="hello";
    u="World";
    std::string::iterator y=x.begin()+8;

    x.append(u);  //or x=x+u;

    x.insert(5," hai ");
    std::cout<<x.length()<<"   ";
    std::cout<<x<<std::endl;
    return 0;
}