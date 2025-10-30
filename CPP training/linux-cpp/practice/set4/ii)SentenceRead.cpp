#include<iostream>

using namespace std;
void numberofVowels(string *s,int n);
int main()
{
    int n = 0;
    cout<<"Enter number of sentences"<<endl;
    cin>>n;
    cin.ignore();
    string s[n];
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
    }
    numberofVowels(s,n);


    return 0;
}
void numberofVowels(string *s,int n)
{
    int vowels = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;s[i][j]!='\0';j++)
        {
            if((s[i][j]=='a')||(s[i][j]=='e')||(s[i][j]=='i')||(s[i][j]=='o')||(s[i][j]=='u')||
               (s[i][j]=='A')||(s[i][j]=='E')||(s[i][j]=='I')||(s[i][j]=='O')||(s[i][j]=='U'))
            {
                vowels++;
            }
        }
        cout<<"number of vowels in sentence "<<i+1<<" is "<<vowels<<endl;
        vowels=0;
    }
}