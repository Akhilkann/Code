#include<iostream>
#include<map>
#include<cstring>


class Person{
    public:
    int id;
    char *name;
    int age;
    Person(){}
    Person(int ID,char * NAME,int AGE):id(ID),name(new char[strlen(NAME)+1]),age(AGE)
    {
        strcpy(name,NAME);
       // NAME={0};
    }
    Person(const Person& p):id(p.id),name(new char[strlen(p.name)+1]),age(p.age)
    {
        name=p.name;
    }
};
int main()
{
    int ID;
    char Name[10];
    int Age;
    std::map<int,Person> m1;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "enter ID:  " << std::endl;
        std::cin>>ID;
        std::cout << "enter Name:  " << std::endl;
        std::cin>>Name;
        std::cout << "enter Age:  " << std::endl;
        std::cin>>Age;
        m1.insert({ID,Person(ID,Name,Age)});
    }
    for(auto it:m1)
    {
        std::cout << it.first<<"  "<<it.second.name<<"  "<<it.second.age<<std::endl;
    }
    while(1)
    {
        std::cout << "ID to read :  " << std::endl;
        std::cin >> ID;
        try
        {
            std::cout << "Name : " << m1.at(ID).name << "  Age : " << m1.at(ID).age << std::endl; //The .at() function performs runtime bounds checking. If the provided index is outside the valid range of the container, it throws an std::out_of_range exception.
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error:ID doesnt exist " << std::endl;
        }
    }

    //std::cout<<m1[2].age;
    
    return 0;
}