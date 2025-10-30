#include<iostream>
using namespace std;


struct ODD_EVEN
{
    int odd;
    int even;
};

ODD_EVEN Count_Odd_Even(int *ptr,int n);
int main()
{
    cout<<"Enter number of elements"<<endl;
    int n=0;
    cin>>n;
    int *ptr=0;
    
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr!=0)
    {
        cout<<"Enter array elements"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>ptr[i];
        }
    }
    ODD_EVEN ret=Count_Odd_Even(ptr,n);
    cout<<"Even count = "<<ret.even<<"  Odd count = "<<ret.odd<<endl;
    delete(ptr);
    return 0;
}

ODD_EVEN Count_Odd_Even(int *ptr,int n)
{
    ODD_EVEN temp={0,0};
    for(int i=0;i<n;i++)
    {
        if((ptr[i]%2)==0)
        {
            temp.even++;
        }
        else
        {
            temp.odd++;
        }
    }
    return temp;
}