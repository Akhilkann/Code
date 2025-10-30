/*Create a class CEmployee that contains a pointer to a name, and a Social Security 
number as a long integer. Write the constructor and destructor functions and a virtual 
function called print() to print both data members.

Then from class CEmployee, derive a class called hourly_employee that contains new data 
members called rate and hours. Override the print() to display all details of hourly employee.

In addition, derive a class called salaried_employee that contains a new data member called 
salary. Override the print() to display all details of salaried employee.

In the main(), declare array of pointers of hourly employee type and salaried type separately
and maintain a count of each type of employees during creation. Based on the type of 
employee, instantiate corresponding object properly and initilaize its members using the 
constructors. Continue this in a loop until user has completed creating all employee instances
Finally print all the employees with their details.
*/



#include<iostream>
//#include<string>

class CEmployee
{
    protected:
    std::string *name;
    long int number;
    public:
    CEmployee(){name=new std::string;}
    CEmployee(std::string name1,int number):name(new std::string),number(number){*name=name1;}
    ~CEmployee(){delete name;}

    virtual void print()
    {
        std::cout<<"Name: "<<*name<<" Social Security Number: "<<number<<std::endl;
    }
};
class hourly_employee:public CEmployee
{
    int rate;
    int hour;
    
    public:
    static int HEmp_count;
    hourly_employee(){}
    hourly_employee(std::string name1,int number1,int hour,int rate):hour(hour),rate(rate){*name=name1;number=number1;HEmp_count++;}
    ~hourly_employee(){}
    void print() override
    {
        CEmployee::print();
        std::cout<<" Rate: "<<rate<<"  "<<" Hour: "<<hour<<"  "<<std::endl;
    }
};
int hourly_employee::HEmp_count=0;

class salaried_employee:public CEmployee
{
    int salary;
    static int SEmp_count;
    public:
    salaried_employee(){}
    salaried_employee(std::string name1,int number1,int sal):CEmployee(name1,number1),salary(sal){SEmp_count++;}
    void print() override
    {
        std::cout<<"Name:"<<*name<<" ssn no:"<<number<<" salary: "<<salary<<"  "<<std::endl;
    }
};
int salaried_employee::SEmp_count=0;

int main()
{
    hourly_employee *HEmp[10];
    salaried_employee *SEmp[10];

    using namespace std;

    char input_type;
    int quit=0,HEmp_index=0,SEmp_index=0;
    while(!quit)
    {
    cout<<"Enter employee details for hourly- h , salaried- s , quit- q"<<endl;
    cin>>input_type;
    if(input_type=='h')
    {
        string name;
        int number,rate,hour;
        cout<<"Enter name :";
        cin>>name;
        cout<<endl<<"Enter ssn number:";
        cin>>number;
        cout<<endl<<"Enter rate:";
        cin>>rate;
        cout<<endl<<"Enter hour:";
        cin>>hour;

        HEmp[HEmp_index++]=new hourly_employee(name,number,rate,hour);
    }
    else if(input_type=='s')
    {
        string name;
        int number,salary;
        cout<<"Enter name :";
        cin>>name;
        cout<<endl<<"Enter ssn number:";
        cin>>number;
        cout<<endl<<"Salary:";
        cin>>salary;

        SEmp[SEmp_index++]=new salaried_employee(name,number,salary);
    }
    else if (input_type=='q')
    {
        quit=1;
    }
    
    }
    cout<<"--------Printing datas for hourly Employees--------------"<<endl;
    for(int i=0;i<hourly_employee::HEmp_count;i++)
    {
        HEmp[i]->print();
    }
    cout<<"--------Printing datas for salaried Employees--------------"<<endl;
    for(int i=0;i<SEmp_index;i++)
    {
        SEmp[i]->print();
    }

}