#include <iostream>

using namespace std;

class CTime
{
    int hour;
    int minute;
    int seconds;

public:
    CTime();
    CTime(int, int, int);
    CTime(const CTime &);

    void displaytime();
    void displaytime(const char *);
    int incrementsec();
};

CTime::CTime() {}
CTime::CTime(int h, int m, int s) : hour(h), minute(m), seconds(s) {}
CTime::CTime(const CTime &a) : hour(a.hour), minute(a.minute), seconds(a.seconds) {}

void CTime::displaytime()
{
    cout << hour << ":" << minute << ":" << seconds << endl;
}
void CTime::displaytime(const char *s)
{
    if (s == "24HR")
    {
        cout << hour << ":" << minute << ":" << seconds << endl;
    }
    else if (s == "12HR")
    {
        if(hour>12)
        {
            cout << hour-12 << ":" << minute << ":" << seconds <<" PM"<< endl;
        }
        else
        cout << hour << ":" << minute << ":" << seconds <<" AM "<< endl;
    }
    else
    {
        cout << "Invalid entry" << endl;
    }
}
int CTime::incrementsec()
{
    seconds++;
    if(seconds>=60)
    {
        seconds=0;
        if(++minute>=60)
        {
            minute=0;
            if(++hour>=24)
            {
                hour=0;
                return 1;
            }
        }
        
    }
    return 0;
}

class CDate
{
    CTime time1;
    int day;
    int month;
    int year;
    static int array[12];
public:
    CDate();
    CDate(int,int,int,int,int,int);
    void increment();
    void display();
};
int CDate::array[]={31,28,31,30,31,30,31,31,30,31,30,31};

CDate::CDate(){}
CDate::CDate(int h,int m, int s,int dt,int mn, int yr):time1(h,m,s),day(dt),month(mn),year(yr){}
void CDate::increment()
{
    if(time1.incrementsec())
    {
        day++;
        if(day>array[month-1])
        {
            day=1;
            if(++month>12)
            {
                month=1;
                year++;
            }
        }
    }
}
void CDate::display()
{
    cout<<day<<"/"<<month<<"/"<<year<<endl;
    time1.displaytime();
    time1.displaytime("12HR");
}
int main()
{
    CDate A(13,29,0,5,6,2025);
    for(int i=0;i<10000;i++)
    {
        A.increment();
    }
    A.display();  //output should be date:5/6/2025 & time 16:15:40

    return 0;
}