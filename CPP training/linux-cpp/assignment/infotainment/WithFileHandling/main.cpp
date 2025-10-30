#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<string.h>
#include"FileRead.hpp"
using namespace std;
int no_of_Medialines = 0;
int no_of_Radiolines = 0;

void Radio_out(int inp2 ,struct RadioST *ptr);
void Media_out(int inp2 ,struct MediaST *ptr);
int main()
{

    
    int fileReadStatus1 = true ,fileReadStatus2 = true;
    
    no_of_Medialines=Number_of_Lines("Media.txt");
    no_of_Radiolines=Number_of_Lines("Radio.txt");

    MediaST MediaST_PTR[no_of_Medialines];
    RadioST RadioST_PTR[no_of_Radiolines];

    fileReadStatus1 = ReadMediaFile("Media.txt",MediaST_PTR);
    fileReadStatus2 = ReadRadioFile("Radio.txt",RadioST_PTR);

    if((fileReadStatus1 == false)&&(fileReadStatus2 == false))
    {
        int input1=1,input2=0;
        while (input1)
        {
            cout << "---------Enter your choice--------" << endl;
            cout << "------1.Radio  2.Media  0.Exit----\n" << endl;

            cin >> input1;
            switch (input1)
            {
            case 1:
                cout << "-------Enter your choice-------" << endl;
                cout << "-------1.ALL  2.FM  3.AM-------" << endl;
                cin >> input2;
                Radio_out(input2,RadioST_PTR);
                break;
            case 2:
                cout << "------Enter your choice--------" << endl;
                cout << "---1.ALL  2.ARTIST  3.ALBUM----" << endl;
                cin >> input2;
                Media_out(input2, MediaST_PTR);
                break;
            }
        }
    }

}

void Radio_out(int inp2 ,struct RadioST *ptr)
{
    switch(inp2)
    {
        case 1:
        for(int i=0;i<no_of_Radiolines;i++)
        {
            cout<<"\n"<<ptr[i].Type<<endl;
            cout<<ptr[i].Frequency<<endl;
        }
        break;
        case 2:
        for(int i=0;i<no_of_Radiolines;i++)
        {
            
            if(ptr[i].Type=="FM")
            {
            cout<<"\n"<<ptr[i].Type<<endl;
            cout<<ptr[i].Frequency<<endl;
            }
        }
        break;
        case 3:
        for(int i=0;i<no_of_Radiolines;i++)
        {
            
            if(ptr[i].Type=="AM")
            {
            cout<<"\n"<<ptr[i].Type<<endl;
            cout<<ptr[i].Frequency<<endl;
            }
        }
        break;
    }
}

void Media_out(int inp2 ,struct MediaST *ptr)
{
    int inp1=0,flag=0;
    switch(inp2)
    {
        case 1:
        for(int i=0;i<no_of_Medialines;i++)
        {
            cout<<"\n"<<ptr[i].Song_name<<endl;
            cout<<ptr[i].Artist_name<<endl;
            cout<<ptr[i].Album_name<<endl;
            cout<<ptr[i].Duration<<endl;
        }
        break;
        case 2:
        cout<<"\n"<<endl;
        cout<<"(0) "<<ptr[0].Artist_name<<endl;
        for(int i=1;i<no_of_Medialines;i++)
        {flag=0;
            for(int j=0;j<i;j++)
            {
                if(ptr[i].Artist_name==ptr[j].Artist_name)
                {
                    flag=1;
                }
            }
            if(flag!=1)
            {
                cout<<"("<<i<<") "<<ptr[i].Artist_name<<endl;
                flag=0;
            }
        }
        cout<<"------Make a selection----"<<endl;
        cin>>inp1;
        cout<<"--------------------------"<<endl;
        for(int i=0;i<no_of_Medialines;i++)
        {
            if(ptr[inp1].Artist_name==ptr[i].Artist_name)
            {
                flag=1;
                cout<<"("<<i<<") "<<ptr[i].Song_name<<endl;
            }
        }
        if(flag==1)
        {
            cout<<"------Choose a song------"<<endl;
            cin>>inp1;
            cout<<"-------------------------"<<endl;
            if(inp1>=0 && inp1<no_of_Medialines)
            {
                cout<<"\n"<<ptr[inp1].Song_name<<endl;
            cout<<ptr[inp1].Artist_name<<endl;
            cout<<ptr[inp1].Album_name<<endl;
            cout<<ptr[inp1].Duration<<endl;
            }
        }
        break;
        case 3:
        cout<<ptr[0].Album_name<<endl;
        for(int i=1;i<no_of_Medialines;i++)
        {
            flag=0;
            for(int j=0;j<i;j++)
            {
                if(ptr[i].Album_name==ptr[j].Album_name)
                {
                    flag=1;
                }
            }
            if(flag!=1)
            {
                cout<<ptr[i].Album_name<<endl;
                flag=0;
            }
        }
        break;
        default:
        
        break;
    }
}

        