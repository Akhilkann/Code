#include<iostream>
using namespace std;

int  first_diagonal_sum(int *ptr,int m,int n);
int* allocate_memory(int n);
int second_diagonal_sum(int *ptr,int m,int n);
int  take_input(int *ptr,int n);
int main()
{
    int m,n,sum=0;
    cout<<"Enter m =";cin>>m;
    cout<<"\nEnter n =";cin>>n;

    int *ptr=0;
    ptr=allocate_memory(m*n);
    if (ptr)
    {
        cout << "Allocated matrix" << endl;
        for (int i = 0; i < m; i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<*(ptr+(i*n)+j)<<"  ";
            }
            cout<<endl;
        }
        
        /*Read input matrix*/
        take_input(ptr,m*n);
        
        /*Printing Updated Matrix*/
        cout<<"Updated Matrix"<<endl;
        for (int i = 0; i < m ; i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<*(ptr+(i*n)+j)<<"  ";
            }
            cout<<endl;
        }

        /*sum of elemts in first diagonal*/
       
        sum=first_diagonal_sum(ptr,m,n);
        cout << "Sum of elements in the first diagonal is  " << sum << endl;

        /*sum of elements in second diagonal*/

        sum=second_diagonal_sum(ptr,m,n);
        cout<<"Sum of elements in the second diagonal is  "<<sum<<endl;
    }
    delete(ptr);
    return 0;
}


int  first_diagonal_sum(int *ptr,int m,int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++, cout << "\n")
    {
        sum = sum + *(ptr + (i * n) + i);
    }
    return sum;
}

int second_diagonal_sum(int *ptr,int m,int n)
{
    int sum=0;
    for (int i = 0; i < m; i++)
    {
        sum = sum + *(ptr + (i * (n - 1)) + (n - 1));
    }
    return sum;
}
int* allocate_memory(int n)
{
    int *ptr=0;
    ptr=new int[n];
    return ptr;
}

int  take_input(int *ptr,int n)
{
    cout << "\nEnter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ptr[i];
    }
    return 0;
}