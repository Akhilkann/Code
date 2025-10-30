#include<iostream>
using namespace std;
struct time
{
    int nHours;
    int nMinutes;
    int nSeconds;
};
struct date_time
{
    int nDay;
    int nMonth;
    int nYear;
    struct time TM;
};

int increment_by_1(date_time *ptr);

int main()
{
    date_time DT={28,5,2025,{14,51,00}};
   cout <<"Initialized time and date"<<endl;
    cout<<"Day="<<DT.nDay<<"/Month="<<DT.nMonth<<"/Year="<<DT.nYear<<endl;
    cout<<"Sec :"<<DT.TM.nSeconds<<"/ Mn :"<<DT.TM.nMinutes<<"/ Hr :"<<DT.TM.nHours<<endl;

    int loop =0;
    cout<<"\nEnter number of seconds to increment"<<endl;
    cin>>loop;
    for(int i=0;i<loop;i++)
    {
        increment_by_1(&DT);
    }
    cout<<"\nAfter incrementing"<<endl;
    cout<<"Day="<<DT.nDay<<"/Month="<<DT.nMonth<<"/Year="<<DT.nYear<<endl;
    cout<<"Sec :"<<DT.TM.nSeconds<<"/ Mn :"<<DT.TM.nMinutes<<"/ Hr :"<<DT.TM.nHours<<endl;

    return 0;
}
int increment_by_1(date_time *ptr)
{
    static int monthdays =31;
    ptr->TM.nSeconds++;
    if(ptr->TM.nSeconds>=60)
    {
        ptr->TM.nSeconds=0;
        ptr->TM.nMinutes++;
        if(ptr->TM.nMinutes>=60)
        {
            ptr->TM.nMinutes=0;
            ptr->TM.nHours++;
            if (ptr->TM.nHours >= 24)
            {
                ptr->TM.nHours = 0;
                ptr->nDay++;
                if ((ptr->nDay > 28) && (ptr->nMonth == 2))
                {

                    ptr->nDay = 1;
                    ptr->nMonth++;
                }
                else if ((ptr->nDay > 31)&&(ptr->nMonth==1||ptr->nMonth==3||ptr->nMonth==5||ptr->nMonth==7||ptr->nMonth==8||ptr->nMonth==10||ptr->nMonth==12))
                {
                    ptr->nDay = 1;
                    ptr->nMonth++;
                }
                else if((ptr->nDay > 30)&&(ptr->nMonth==4||ptr->nMonth==6||ptr->nMonth==9||ptr->nMonth==11))
                {
                    ptr->nDay = 1;
                    ptr->nMonth++;
                }
                if (ptr->nMonth > 12)
                {
                    ptr->nMonth = 1;
                    ptr->nYear++;
                }
            }
        }
        
    }

    return 0;

}