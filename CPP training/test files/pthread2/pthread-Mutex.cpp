#include<iostream>
#include<pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t M;

int SharedVariable=10;

void* fun1(void* arg)
{
    
    for(int i=0;i<10;i++)
    {
        pthread_mutex_lock(&M);
        SharedVariable++;
        cout<<"fun1 called  -SharedVariable= "<<SharedVariable<<endl;
        pthread_mutex_unlock(&M);
        sleep(.5);
    }

    return NULL;
}
void* fun2(void* arg)
{
    
    for(int i=0;i<10;i++)
    {
        pthread_mutex_lock(&M);
        SharedVariable++;
        cout<<"fun2 called  -SharedVariable= "<<SharedVariable<<endl;
        pthread_mutex_unlock(&M);
        sleep(.5);
    }
    return NULL;
}


int main()
{
    pthread_t pthread1,pthread2;
    pthread_create(&pthread1,NULL,fun1,(void*)NULL);  //4 th argument is the argument passing to the fun1
    pthread_create(&pthread2,NULL,fun2,(void*)NULL);

    pthread_join(pthread2,NULL);  //second argument is is a pointer to a location where the return value of the thread will be stored.
    pthread_join(pthread1,NULL);

    return 0;
}