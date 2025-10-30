#include<iostream>
using namespace std;




int main()
{


    int input = 0 , sum = 0 ,temp = 0,temp2 =1;
    for(int i=1;i<=500;i++)
    {
        input=i;
        do
        {
            temp=input%10;
            sum=sum+(temp*temp*temp);
            input=input/10;
        } while (input);
        if(sum==i)
        {
            if(temp2==1)
            {
                cout<<"Armstrong numbers within 1 and 500 are--"<<endl;
                temp2 = 0;
            }
            cout<<i<<" , ";
        }
        sum=0;

    }
    cout<<endl;
    return 0;
}