#include<iostream>
#include<set>

class greater
{ 
    public:
    bool operator()(int a,int b) const
    {
    return a>b;
    }
};

int main()
{

    std::set<int> x;
    x.insert(2);
    x.emplace(10);
    x.insert(23);
    for(auto it1:x)
    {
        std::cout<<it1<<std::endl;
    }

    /*Find an element*/
    auto it=x.find(10);
    if(it!=x.end())
    {
        std::cout<<"Element found"<<std::endl;
    }
    else  std::cout<<"Element not found"<<std::endl;

    /*Delete an element*/
    x.erase(10);
    for(auto it1:x)
    {
        std::cout<<it1<<std::endl;
    }

    /*Size of set*/
    std::cout<<"size of set  :"<<x.size()<<std::endl;


    //////////////////////////////////////////////////

    std::set<int,greater> y={1,2,3,4,5}; 
    for(auto it2:y)
    {
        std::cout<<it2<<std::endl;
    }

    return 0;
}