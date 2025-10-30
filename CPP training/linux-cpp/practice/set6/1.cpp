#include<iostream>

using namespace std;

int days_Array[] = {31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class CDate_{
    int day;
    int month;
    int year;
    public:
    void setDate(int d,int m,int y);
    void incrmentDate();
    void displayDate();


};

void CDate_::setDate(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}
void CDate_::incrmentDate()
{
    day++;
    if(day>days_Array[month-1])
    {
        day = 1;
        month++;
        if(month>12)
        {
            month = 1;
            year++;
        }
        cout<<endl;
    }
}

void CDate_::displayDate()
{
    cout<<month<<" /"<<day<<" /"<<year<<endl;
}

int main() {
CDate_ today;
today.setDate(01, 01,1993);
for(int i = 0; i<400; i++) {
today.incrmentDate();
today.displayDate();
}
return 0;
}