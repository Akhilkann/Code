#include<iostream>
#include<cstring>

using namespace std;

class CDriver{
public:
    char *name;
    int age;

    CDriver(){}
    CDriver(const char *,int);
    void print();
    //~CDriver(){delete(name);}


};
CDriver::CDriver(const char *str,int y):name(nullptr),age(y)
{
    if(str)
    {
        name=new char[strlen(str)+1];
        strcpy(name,str);
    }
}
void CDriver::print()
{
    cout<<name<<"  "<<age<<"  ";
}

class CAutomobile{
public:
    CDriver CDrv;
    char *make;
    int year;

    CAutomobile(){}
    CAutomobile(const char* strName,int Ag,const char* strMake,int yr); 
    //~CAutomobile(){delete(make);}
    void print();

};
CAutomobile::CAutomobile(const char* strName,int Ag,const char* strMake,int yr):CDrv(strName,Ag),make(nullptr),year(yr)
{
    if(strMake)
    {
        make=new char[strlen(strMake)+1];
        strcpy(make,strMake);
    }
}

void CAutomobile::print()
{
    CDrv.print();
    cout<<make<<"  "<<year<<endl;
}

void sort(CAutomobile** ptr,int n)
{
    CAutomobile *temp=nullptr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(ptr[j]->CDrv.age>ptr[j+1]->CDrv.age)
            {
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
}

int main()
{
    cout<<"Enter number of details to enter"<<endl;
    int n=0;
    cin>>n;
    CAutomobile **ptr;
    ptr=new CAutomobile*[n];
    for(int i=0;i<n;i++)
    {
        ptr[i]=new CAutomobile();
        int temp=0;
        cout<<"---------Enter detail "<<i+1<<"-------"<<endl;
        cout<<"\nName = ";
        ptr[i]->CDrv.name=new char;
        cin.ignore();
        cin.getline(ptr[i]->CDrv.name,10);
        cout<<"\nAge = ";
        cin>>ptr[i]->CDrv.age;
        cout<<"\nMake = ";
        cin.ignore();
        ptr[i]->make=new char;
        cin.getline(ptr[i]->make,10);
        cout<<"\nyear = ";
        cin>>ptr[i]->year;
        cout<<endl;

    }
    cout<<"--------sorting completed---------"<<endl;
    sort(ptr,n);
    for(int i=0;i<n;i++)
    {
        ptr[i]->print();
        cout<<endl;
        delete(ptr[i]->CDrv.name);
        delete(ptr[i]->make);
        delete(ptr[i]);
    }
    delete(ptr);
    return 0;
}