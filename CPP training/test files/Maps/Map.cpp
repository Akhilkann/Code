#include<iostream>
#include<map>
#include<string>

int main()
{
    // std::map<int,std::string> x;
    // x={{4,"four"},{2,"two"},{3,"three"}};
    // x.insert({1,"one"});
    // for (auto i:x)
    // {
    //     std::cout<<i.first<<"  "<<i.second<<std::endl;
    // }
    
    // x[2]="twooo";
    // std::cout<<x[1]<<"  "<<x[2]<<std::endl;


    std::map<std::string,int> y;
    y.insert({"one",1});
    y.insert({"two",2});
    y.insert({"three",3});
    y["one"]=11;
    std::cout<<y["one"]<<" "<<y["two"]<<" "<<y["three"]<<" "<<y.at("two")<<std::endl;
    for (auto i:y)
    {
        std::cout<<i.first<<"  "<<i.second<<std::endl;
    }


    /*find an element*/
    auto it=y.find("three");
    std::cout<<"Find three-"<<it->first<<"  "<<it->second<<std::endl;

    /*delete element*/
    y.erase("one");
    std::cout<<"erase one"<<std::endl;
    for (auto i:y)
    {
        std::cout<<i.first<<"  "<<i.second<<std::endl;
    }

    return 0;
}