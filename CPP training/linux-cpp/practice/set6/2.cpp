#include<iostream>
#include<cstring>
using namespace std;

class CIn_Out{
    
    char buffer[80];

    public:
    int read();
    void convert();
    void print();

};

int CIn_Out::read()
{
    memset(buffer, 0, sizeof(buffer)); // Sets all elements to '\0'
    if(cin.getline(buffer,80))
    {
        return false;
    }
    else
    return true;
}

void CIn_Out::convert()
{
    for(int i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]>=65)&&(buffer[i]<=90))
        {
            buffer[i]+=32;
        }
        else if((buffer[i]>=97)&&(buffer[i]<=122))
        {
            buffer[i]-=32;
        }
        else
        {
            //do nothing
        }
    }
}

void CIn_Out::print()
{
    for(int i=0;buffer[i]!='\0';i++)
    {
        cout<<buffer[i];
    }
}

int main()
{
CIn_Out io;
cout << endl <<"Enter some data : ";
while (!io.read()) //Reads a single string
{
io.convert();
io.print();
cout << endl << "Next data : ";
}
return 0;
}