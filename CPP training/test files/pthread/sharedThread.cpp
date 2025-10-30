#include<iostream>
#include<thread>
#include<mutex>
#include <shared_mutex>


std::shared_mutex m2;

int SharedMem=0;
void func1(void *ptr)
{
    //std::unique_lock lck(m2);  //lock shared mutex m2 and automatically unlocks when goes out of scope.
    
    for(int i=20;i;i--)
    {
        std::unique_lock lck(m2);  //lock shared mutex m2 and automatically unlocks when goes out of scope.
        SharedMem++;
        std::cout << (char *)ptr << "SharedMem = " << SharedMem << std::endl;
    }
}

void func2(void *ptr)
{
    
     for(int i=20;i;i--)
    {
        std::shared_lock lck(m2);   /* sharing memory between threads while reading from shared memory. 
    While writing to shared mem via thread1 (unique_lock locked) shared_lock will locks and unable to read at that time*/
        std::cout<<(char*)ptr<<"SharedMem = "<<SharedMem<<std::endl;
    }
}


int main()
{
#if 0
    {
    std::jthread thread1(func1,((char*)"thread1"));   //std::jthread calls join() automatically after declaration. no need of thread1.join()
    }   /*call std::jthread with in a scope to complete the task inside the scope.Otherwise there is a chance to complete the task after the execution of the main*/
#else

    std::thread thread1(func1,(char*)"thread1");
    std::thread thread2(func2,(char*)"thread2");
    std::thread thread3(func2,(char*)"thread3");
    std::thread thread4(func2,(char*)"thread4");
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    std::cout<<"End of program"<<std::endl;
#endif
    return 0;
}