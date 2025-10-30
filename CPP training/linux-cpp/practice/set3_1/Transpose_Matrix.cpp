#include<iostream>

using namespace std;
int m = 0, n = 0 ;
int transpose(int *arr,int r,int c);

int main()
{
    
    cout<<"Enter number of rows =";
    cin>>m;
    cout<<endl;
    cout<<"Enter number of coloumns =";
    cin>>n;
    cout<<endl;

    int Matrix[m][n]={0};

    cout<<"Enter the Matrix\n"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Row "<<i<<endl;
        for(int j=0;j<n;j++)
        {
            cin>>Matrix[i][j];
        }
        cout<<"\n";
    }
    cout<<"Input Matrix"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    int ret=transpose((int *)Matrix,m,n);
    return 0;
}

int transpose(int *arr,int r,int c)
{
    cout<<"Transpose of Matrix"<<endl;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<*((arr+j*c)+i)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}