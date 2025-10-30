#include<iostream>
using namespace std;

static int day_table[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class CUserDate { 
int m_nMonth; 
int nDay; 
public: 
//Add constructor and required public functions to give absolute days 
//from the CUserDate object. 
CUserDate(int,int);
int calculateabsolutedays();
};

CUserDate::CUserDate(int a,int b):m_nMonth(a),nDay(b){}

int CUserDate::calculateabsolutedays()
{
    int days=0;
    for(int i=0;i<m_nMonth-1;i++)
    {
        days+=day_table[i];
    }
    days+=nDay;
    return days;
}

int main() {
CUserDate d1(3, 20);
cout << d1.calculateabsolutedays()<<endl;
//Try creating object with different inputs
}