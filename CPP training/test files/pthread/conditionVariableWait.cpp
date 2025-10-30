#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>


std::mutex m1;
std::condition_variable cv;

bool dataUpdated=false;
bool datareceived =true;  //enabling datarecived to true for sending the data from thread1 to thread2 -first time.

int SharedMem=0;

void func1(void *ptr)
{
    //std::unique_lock lck(m2);  //lock shared mutex m2 and automatically unlocks when goes out of scope.
    
    for(int i=20;i;i--)
    {
        std::unique_lock lck(m1);  //lock shared mutex m2 and automatically unlocks when goes out of scope.
        cv.wait(lck,[](){return datareceived;});   //wait to datareceived flag to become true by thread2/func2
        SharedMem++;
        std::cout << (char *)ptr << " -SharedMem value = " << SharedMem << std::endl;
        dataUpdated=true;
        datareceived=false;
        cv.notify_one();  //notify thread2 that dataUpdated
    }
}

void func2(void *ptr)
{
     for(int i=20;i;i--)
    {
        std::unique_lock lck(m1);
        cv.wait(lck,[](){return dataUpdated;}); //wait to dataUpdated flag to become true by thread1/func1

        std::cout<<(char*)ptr<<" -SharedMem value = "<<SharedMem<<std::endl;
        datareceived=true;
        dataUpdated=false;
        cv.notify_one(); //notify thread1 that datareceived
        
    }
}


int main()
{
    
    std::thread thread1(func1,(char*)"thread1");
    //std::thread thread3(func1,(char*)"thread3");
    std::thread thread2(func2,(char*)"thread2");
    thread1.join();
    thread2.join();
    //thread3.join();
    std::cout<<"End of program"<<std::endl;

    return 0;
}