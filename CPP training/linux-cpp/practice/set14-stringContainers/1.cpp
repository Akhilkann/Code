#include<iostream>
#include<vector>
#include<cstdlib>


int main()
{
    int x=1;
    std::vector<std::string> str;
    while (1)
    {
        system("clear");
        std::cout << "enter 1 to read string" << std::endl;
        std::cout << "enter 2 to print string" << std::endl;
        std::cin>>x;
        while (x==1)
        {   
            system("clear");
            std::cout << "enter the string" << std::endl;
            std::string temp;
            std::cin >> temp;
            std::cout << "enter 0-Menu, 1-continue, 2-print ";
            std::cin>>x;
            str.push_back(temp);
            if(x==2)
            {
                std::cout<<std::endl;
                for(int i=0;i<str.size();i++)
                {
                    std::cout <<str[i]<< std::endl;
                }
            std::cout << "enter 0-Menu, 1-continue ";
            std::cin>>x;
            }
            
        }
        while(x==2)
        {
            system("clear");
            for(auto it=str.begin();it!=str.end();it++)
            {
                 std::cout <<*it<< std::endl;
            }
            std::cout << "enter any to menu  ";
            std::cin>>x;
            x=3;
        }
    }
    return 0;
}