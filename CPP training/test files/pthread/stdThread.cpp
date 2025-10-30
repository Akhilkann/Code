#include<iostream>
#include<thread>
#include<mutex>

std::mutex m;

int SharedMem=0;
void func1(void *ptr)
{
    std::lock_guard lck(m);  //lock mutex m and automatically unlocks when goes out of scope . No need to unlock manually m.unlock()
    //m.lock();  //if using lock() you should explicitly use unlock() to free the resourse
    for(int i=10;i;i--)
    {
        
    SharedMem++; 
    std::cout<<(char*)ptr<<"SharedMem = "<<SharedMem<<std::endl;
    }
    //m.unlock(); // Not needed if using std::lock_guard
}


int main()
{
#if 0
    {
    std::jthread thread1(func1,((char*)"thread1"));   //std::jthread calls join() automatically after declaration. no need of thread1.join()
    }   /*call std::jthread with in a scope to complete the task inside the scope.Otherwise there is a chance to complete the task after the execution of the main*/
#else

    std::thread thread1(func1,(char*)"thread1");
    std::thread thread2(func1,(char*)"thread2");
    thread1.join();
    thread2.join();
    std::cout<<"End of program"<<std::endl;
#endif
    return 0;
}