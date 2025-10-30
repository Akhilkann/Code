#include<iostream>

using namespace std;

int main()
{
    int matrix[3][2];
    cout<<"Enter the matrix elements"<<endl;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>matrix[i][j];
        }
        cout<<"\n";
    }

    int **ptr;
    ptr=new int*[2];
    for(int i=0;i<2;i++)
    {
        ptr[i]=new int[3];
        for(int j=0;j<3;j++)
        {
            ptr[i][j]=matrix[j][i];
        }
    }
    cout<<"Matrix"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Transpose"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<"\n";
    }
    delete(ptr);
    return 0;
}