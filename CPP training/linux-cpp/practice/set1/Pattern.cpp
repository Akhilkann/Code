#include<iostream>
using namespace std;

int main()
{
    int count = 4;
     /*-------------------------------*/
    cout<<"1"<<endl;
    while(count--)
    {
        std::cout<<"**********"<<std::endl;
    }
    
    /*------------------------------*/
    cout<<"2"<<endl;
    count=1;
    do
    {
        for(int i=0;i<count;i++)
        {
            cout<<"*";
        }
        count++;
        cout<<"\n"<<endl;
    } while (count<=4);
    /*-------------------------------*/
    cout<<"3"<<endl;
    int x=5,y=4,z=1;
    for(int i=0;i<x;i++)
    {
        //x--;
        for(int j=0;j<y;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<z;k++)
        {
            cout<<"*";
           
        }
        cout<<"\n"<<endl;
         z=z+2;
         y--;
         

    }
    




    return 0;
}