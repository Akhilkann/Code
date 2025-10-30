#include<iostream>
using namespace std;

struct coin {
int nDenominations;
int nCount;
};

int initialize(coin *ptr);
int calculate(coin *ptr,int Amt);
int display(coin *ptr);

int main()
{
    coin coin1[5];
    float Amount = 0;
    int ret = initialize(coin1);
    if (!ret)
    {
        cout<<"Enter Amount"<<endl;
        cin>>Amount;
        ret=calculate(coin1,Amount*100);
        if(!ret)
        {
            display(coin1);
        }
    }
    return 0;
}

int initialize(coin *ptr)
{
    ptr[0].nDenominations=500;  //500Ps->5Rs
    ptr[1].nDenominations=200;  //200Ps->2Rs
    ptr[2].nDenominations=100;  //100Ps->1Rs
    ptr[3].nDenominations=50;   //50Ps
    ptr[4].nDenominations=25;   //25Ps
    for(int i=0;i<5;i++)
    {
        ptr[i].nCount=0;     
    }
    return 0;
}

int calculate(coin *ptr,int Amt)
{
    for(int i=0;i<5;i++)
    {
        ptr[i].nCount=Amt/ptr[i].nDenominations;
        Amt=Amt%ptr[i].nDenominations;
    }
    return 0;
}

int display(coin *ptr)
{
    cout<<"Denomination     Count"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<((ptr[i].nDenominations>=100)?((ptr[i].nDenominations==100)?"Re.":"Rs."):"Ps")<<
        ((ptr[i].nDenominations/100>=1)?ptr[i].nDenominations/100:ptr[i].nDenominations)<<"           "<<ptr[i].nCount<<endl;
    }

    return 0;
}