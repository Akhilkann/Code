#include<iostream>
#include<string>
#include <cmath>

using namespace std;

class CCoin
{
int m_nDenom; //5 rupees or 2 rupees 0r 1 rupee or 50ps or 25ps
long m_nCount; //Count of occurances of coin type
const char* scointype; //whether rupees or paise
public:
////
CCoin(int x);
void change(double& a);
void print();
};

CCoin::CCoin(int x):m_nDenom(x)
{
    if((x>=1)&&(x<=5))
    {
        scointype="rupee";
    }
    else{ scointype="paise";}
    
}
void CCoin::change(double& a)
{
    if((scointype=="rupee")&&(a>0))
    {
        m_nCount=a/m_nDenom;
        a=fmod(a,m_nDenom);
        //cout<<m_nCount<<" "<<m_nDenom<<"a="<<a<<endl;;
    }
    else if((scointype=="paise"))
    {
        double temp=(double)m_nDenom/100;
        m_nCount=a/(temp);
        a=fmod(a,temp);
        //cout<<m_nCount<<" "<<m_nDenom<<"a="<<a<<" temp="<<temp<<endl;;
        
    }
    else{/*Do nothing*/}
}
void CCoin::print()
{
    cout<<m_nCount<<"  "<<m_nDenom<<" "<<scointype<<endl;
}

int main()
{
CCoin* pCoin[5];
double dAmount;
pCoin[0] = new CCoin(5);// 5 is the value with which denomination needs
//to be set.
pCoin[1] = new CCoin(2);// 2 is the value with which denomination needs
//to be set.
pCoin[2] = new CCoin(1); // 1 is the value with which denomination needs
//to be set.
pCoin[3] = new CCoin(50); //50 is the value with which denomination needs
//to be set.
pCoin[4] = new CCoin(25); //25 is the value with which denomination needs
//to be set.
cout << endl << "Enter amount";
cin >> dAmount;
for (int i = 0; i < 5; i++)
{
pCoin[i]->change(dAmount); // Calculate how many 5 ruppes exists in
//first coin object. If so calculate the //no: of 5 rupees and the amount taken //for next iteration must be the remaining //amount
}
//Print all coin objects
for(int i=0;i<5;i++)
{
    pCoin[i]->print();
}
}