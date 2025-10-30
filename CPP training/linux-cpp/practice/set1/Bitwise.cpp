#include<iostream>

using namespace std;



int main()
{
    cout<<"Enter a number to do bitwise operations"<<endl;
    int input = 0;
    cin>>input;
    cout<<"---------------------------Choose----------------------------------"<<endl;
    cout<<"  1 .To Set a bit   2.Clear a bit   3.Show binary representation   "<<endl;
    int selection = 0;
    cin>>selection;
    int position = 0;
    switch(selection)
    {
        case 1:cout<<"enter bit position to set(32------0)"<<endl;
            
            cin>>position;
            if(position>=0 && position<32)
            {
                input=input|(1<<position);
                cout<<input<<endl;
            }
            break;
        case 2:
        cout<<"enter bit position to clear(32------0)"<<endl;
            cin>>position;
            if(position>=0 && position<32)
            {
                input&=~(1<<position);
                cout<<input<<endl;
            }
            break;
        case 3:
            for(int i=0;i<32;i++)
            {
                if(input&(1<<31))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
                input<<=1;
            }
            cout<<"\n";
            break;
        default:
        break;
    }
    return 0;
}