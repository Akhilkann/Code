#include<iostream>
#include<string.h>
#include"header.hpp"
void func(int inp2, int inp1);
using namespace std;
int inp3=0,flag=0;
int main()
{
int input1=1,input2=0;
while(input1)
{
	cout<<"1.Radio  2.Media  0.Exit"<<endl;
	cout<<"Enter your choice"<<endl;

	cin>>input1;
	switch(input1)
	{
		case 1:cout<<"\n 1.ALL  2.FM  3.AM"<<endl;
		cin>>input2;
		func(input2,input1);
		break;
		case 2:cout<<"\n 1.ALL  2.ARTIST  3.ALBUM"<<endl;
		cin>>input2;
		func(input2,input1);
		break;
	}

}


}

void func( int inp2,int inp1 )
{
switch(inp1)
{
case 1:	switch(inp2)
	{
		case 1:
		for(int i=0;i<3;i++)
		{
			cout<<"\n"<<FM_St[i]<<endl;
			cout<<FM_Fr[i]<<endl;
		}
		for(int i=0;i<3;i++)
                {
                        cout<<"\n"<<AM_St[i]<<endl;
                        cout<<AM_Fr[i]<<endl;
                }
		break;
		case 2: 
		for(int i=0;i<3;i++)
                {
                        cout<<"\n"<<FM_St[i]<<endl;
                        cout<<FM_Fr[i]<<endl;
                }
		break;
		case 3:
		for(int i=0;i<3;i++)
                {
                        cout<<"\n"<<AM_St[i]<<endl;
                        cout<<AM_Fr[i]<<endl;
                }
		break;
		default:cout<<"Invalid selection"<<endl;

	}
break;
case 2: switch(inp2)
{
	case 1:
	for(int i=0;i<5;i++)
        {
             cout<<"\n"<<Song[i]<<endl;
             cout<<Artist[i]<<endl;
		cout<<Album[i]<<endl;
		cout<<Dur[i]<<endl;
        }
	break;
	case 2:
	for(int i=0;i<5;i++)
	{
		cout<<" ("<<i<<")- "<<Artist[i];
	}
	cout<<"\nmake a selection"<<endl;
	cin>>inp3;
		for(int i=0;i<5;i++)
		{
		if(strcmp(Artist[i],Artist[inp3])==0)
		{flag=1;
			cout<<" ("<<i<<")"<<Song[i]<<endl;
		}
		}
		if(flag==1)
		{
		cout<<"\nchoose a song"<<endl;
		cin>>inp3;
		if((inp3<5)&&(inp3>=0)){
		   cout<<"\n"<<Song[inp3]<<endl;
             	   cout<<Artist[inp3]<<endl;
                   cout<<Album[inp3]<<endl;
                   cout<<Dur[inp3]<<endl;
		}
		else{cout<<"invalid input"<<endl;}
		}
	break;
	case 3:
	for(int i=0;i<5;i++)
        {
                cout<<"\n"<<Album[i]<<endl;
        }
	break;
	default:cout<<"invalid selection"<<endl; break;
}
}
}
