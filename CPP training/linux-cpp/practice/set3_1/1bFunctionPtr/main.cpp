#include<iostream>
#include<string>
using namespace std;

int Good_String(const char* str);
int Sum_Of_Digits(const char* str);

int main()
{
    char s[20];
    int returnvalue;
    cout<<"Enter string"<<endl;
    cin>>s;
    int (*funcptr)(const char *ptr);
    funcptr=Good_String;
    returnvalue=funcptr(s);
    if(returnvalue==1)
    {
         cout<<"Good string"<<endl;
    }
    else
    {
         cout<<"Not a good string"<<endl;
    }
    funcptr=Sum_Of_Digits;

    returnvalue=funcptr(s);
    cout<<"sum of digits="<<returnvalue<<endl;


    return 0;
}


int Good_String(const char* str)
{
    
    int vowels = 0, consonants = 0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(((str[i]>='A')&&(str[i]<='Z'))||((str[i]>='a')&&(str[i]<='z')))
        {
            if((str[i]=='A')||(str[i]=='E')||(str[i]=='I')||(str[i]=='O')||(str[i]=='U')||
            (str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u'))
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }
    if(vowels>consonants)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int Sum_Of_Digits(const char* str)
{
    int sum = 0, consonants = 0;
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>=48)&&(str[i]<=57))
        {
            sum=sum+(str[i]-48);
        }
    }
    return sum;
}