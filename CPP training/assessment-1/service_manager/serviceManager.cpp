#include<iostream>
#include"service_manager.hpp"



int main()
{
    ServiceManger obj;

    obj.handleMessage(0x10,1,0,"error1");
    obj.handleMessage(0x11,2,0,"error2");
    obj.handleMessage(0x12,3,0,"error3");
    obj.handleMessage(0x13,4,0,"error4");


    return 0;
}