#include<iostream>
using namespace std;

int main()
{
    int vowels = 0,consonants = 0,digits = 0;
    char StringArray[][10]={"qwErty","aeSd23","2144ioUs"};
    for(int i=0;i<3;i++)
    {
        for(int j=0;StringArray[i][j]!='\0';j++)
        {
            if(((StringArray[i][j]>='a')&&(StringArray[i][j]<='z'))||((StringArray[i][j]>='A')&&(StringArray[i][j]<='Z')))
            {
                if((StringArray[i][j]=='a')||(StringArray[i][j]=='e')||(StringArray[i][j]=='i')||(StringArray[i][j]=='o')||(StringArray[i][j]=='u')||
                   (StringArray[i][j]=='A')||(StringArray[i][j]=='E')||(StringArray[i][j]=='I')||(StringArray[i][j]=='O')||(StringArray[i][j]=='U'))
                {
                    vowels++;
                }
                else{
                    consonants++;
                }
            }
            if((StringArray[i][j]>='0')&&(StringArray[i][j]<='9'))
            {
                digits++;
            }
        }
        cout<<"\nstring- "<<i<<endl;
        cout<<"--------------"<<endl;
        cout<<"vowels="<<vowels<<endl;
        cout<<"Consonats="<<consonants<<endl;
        cout<<"Digits="<<digits<<endl;
        vowels=0;consonants=0;digits=0;
    }
    return 0;
}