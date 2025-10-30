#include<iostream>
#include<cstdlib>  //used to clear the screen by calling system(clear)
using namespace std;


struct EMPLOYEE
{
    char chName[40];
    int nEmpId;
    char chGender;
    double dBasicSalary;
};

int sort(struct EMPLOYEE *ptr,int n);
int listDetails(struct EMPLOYEE *ptr, int n);
int SearchEmpID(struct EMPLOYEE *ptr, int n,int id);
int main()
{
    int n=0,loop = 1,input = 0,temp;
    system("clear");  //clear the screen
    cout<<"  Enter number of employee details to enter  "<<endl;
    cin>>n;
    EMPLOYEE EmpDetails[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Emp Name  : "; cin>>EmpDetails[i].chName;
        cout<<"Enter Emp ID    : ";cin>>EmpDetails[i].nEmpId;
        cout<<"Enter Emp Gender: ";cin>>EmpDetails[i].chGender;
        cout<<"Enter Emp Salary: ";cin>>EmpDetails[i].dBasicSalary;
        cout<<"\n";
    }
    cout<<"-----------Enter any number to Menu-----------------"<<endl;
    cin>>temp;
    while(loop)
    {
        system("clear");
        cout<<"----------------------------------Choose-------------------------------"<<endl;
        cout<<"   1.SORT EMP DETAILS BASED ON ID   2. EMPLOYEE LIST  3.SEARCH EMP ID  "<<endl;
        cout<<"----------------------------Press 0 to exit----------------------------"<<endl;
        cin>>input;
        switch (input)
        {
        case 1:{sort(EmpDetails,n);}
            break;
        case 2:{listDetails(EmpDetails,n);}
            break;
        case 3:{int empid = 0;
                cout<<"Enter ID: ";
                cin>>empid;
                SearchEmpID(EmpDetails,n,empid);}
            break;
        default:loop=0;
        break;
        }
    }


    return 0;
}

int sort(struct EMPLOYEE *ptr, int n)
{
    system("clear");
    static int flag = 0;
    if (flag == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (ptr[j].nEmpId > ptr[j + 1].nEmpId)
                {
                    EMPLOYEE temp = {0};
                    temp = ptr[j + 1];
                    ptr[j + 1] = ptr[j];
                    ptr[j] = temp;
                }
            }
        }
        cout << "sorting completed" << endl;
        flag = 1;
    }
    else
    {
        cout<<"Sorting already done"<<endl;
    }
    while(1)
    {
        cout<<"-----------Enter any number to go back-----------------"<<endl;
        int temp;
        cin>>temp;
        return 0;
    }
}

int listDetails(struct EMPLOYEE *ptr, int n)
{
    system("clear");
    for(int i=0;i<n;i++)
    {
        cout<<"Emp Name  : "<<ptr[i].chName<<endl;
        cout<<"Emp ID    : "<<ptr[i].nEmpId<<endl;
        cout<<"Emp Gender: "<<ptr[i].chGender<<endl;
        cout<<"Emp Salary: "<<ptr[i].dBasicSalary<<endl;
        cout<<"\n";
    }
    while(1)
    {
        cout<<"-----------Enter any number to go back-----------------"<<endl;
        int temp;
        cin>>temp;
        return 0;
    }
}
int SearchEmpID(struct EMPLOYEE *ptr, int n,int id)
{
    system("clear");
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        if (ptr[i].nEmpId == id)
        {
            cout << "Emp Name  : " << ptr[i].chName << endl;
            cout << "Emp ID    : " << ptr[i].nEmpId << endl;
            cout << "Emp Gender: " << ptr[i].chGender << endl;
            cout << "Emp Salary: " << ptr[i].dBasicSalary << endl;
            temp = 1;
        }
    }
    if(temp == 0)
    {
        cout<<"Employee with ID: "<<id<<" does not exist"<<endl;
    }
    while(1)
    {
        cout<<"-----------Enter any number to go back-----------------"<<endl;
        int temp;
        cin>>temp;
        return 0;
    }
    
}