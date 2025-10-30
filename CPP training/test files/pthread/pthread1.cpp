#include<iostream>
#include<pthread.h>
#include<string>


void* func1(void *ptr)
{
    for(int i=0;i<10;i++)
    {
    std::cout<<(char*)ptr<<std::endl;
    //std::cout<<(char*)ptr<<std::endl;
    //pthread_exit(NULL);  // function allows a thread to terminate its execution
    //std::cout<<(char*)ptr<<std::endl;
    //std::cout<<(char*)ptr<<std::endl;
    }
    return (int*)true;
}


int main()
{
    pthread_t thread1,thread2;
    if(pthread_create(&thread1,nullptr,func1,(void*)"helloo1")) /*third arg is the thread calling function.Function should have single void* type arg and return void*. */
    {
        std::cerr<<"Error creating thread1"<<std::endl;
    }
    if(pthread_create(&thread2,nullptr,func1,(void*)"helloo2")) /*third arg is the thread calling function.Function should have single void* type arg and return void*. */
    {
        std::cerr<<"Error creating thread2"<<std::endl;
    }

    /*        Wait for the threads to complete       */
    if(pthread_join(thread1,nullptr))  //return 0 if successfull
    {
        std::cerr<<"Error joining the thread1"<<std::endl;
    }
    if(pthread_join(thread2,nullptr))   //return 0 if successfull
    {
        std::cerr<<"Error joining the thread2"<<std::endl;
    }
    
    return 0;
}
