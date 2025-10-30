#include<iostream>
#include<string>
#include<algorithm>   //reverse function to reverse a string is in this header


using namespace std;

string Reverse(string s);
int main()
{
    string input,output;
    cout<<"Enter a string"<<endl;
    cin>>input;
    string (*ptr)(string);
    ptr=Reverse;
    output=ptr(input);
    cout<<"Reversed string"<<endl;
    cout<<output<<endl;


    return 0;
}

string Reverse(string s)
{
    std::reverse(s.begin(),s.end());
    return s;
}