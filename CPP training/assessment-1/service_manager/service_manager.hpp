#include<iostream>

class Service
{

public:
    virtual void handleMessage(int ID, const char * message)
    {
        std::cout << message << "  MsgID:" << ID << std::endl;
    }
};

class VehicleService:public Service{

    public:
    void handleMessage(int ID, const char * message)
    {
        std::cout << "VehicleService--"<<message << "  MsgID:" << ID << std::endl;
    }
};

class RadioService:public Service{

    public:
    void handleMessage(int ID, const char * message)
    {
        std::cout << "RadioService--"<<message << "  MsgID:" << ID << std::endl;
    }
};

class MediaService:public Service{

    public:
    void handleMessage(int ID, const char * message)
    {
        std::cout << "MediaService--"<<message << "  MsgID:" << ID << std::endl;
    }
};

class DiagService:public Service{

    public:
    void handleMessage(int ID, const char * message)
    {
        std::cout << "DiagService--"<<message << "  MsgID:" << ID << std::endl;
    }
};

class ServiceManger{
    Service *array[4];
    public:
    ServiceManger()
    {
        array[0]=new VehicleService;
        array[1]=new RadioService;
        array[2]=new MediaService;
        array[3]=new DiagService;
    }
    void handleMessage(int serviceID,int messageID,int message_length,const char * message);

};

void ServiceManger::handleMessage(int serviceID,int messageID,int message_length,const char * message)
{
    if (serviceID==0x10)
    {
        array[0]->handleMessage(messageID,message);
    }
    if (serviceID==0x11)
    {
        array[1]->handleMessage(messageID,message);
    }
    if (serviceID==0x12)
    {
        array[2]->handleMessage(messageID,message);
    }
    if (serviceID==0x13)
    {
        array[3]->handleMessage(messageID,message);
    }
}

