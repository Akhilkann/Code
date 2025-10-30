#include<iostream>
#include<pthread.h>
#include <unistd.h>
using namespace std;


pthread_mutex_t Mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


int SharedVariable=10;
int variable = 0;

void* fun1(void* arg)
{

    pthread_mutex_lock(&Mut);
    sleep(.5);
    SharedVariable++;
    variable = 1;
    cout <<"fun1 Producer called  -SharedVariable= " << SharedVariable << endl;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&Mut);

    return NULL;
}
void* fun2(void* arg)
{

    pthread_mutex_lock(&Mut);
    while(!variable)
    {
    pthread_cond_wait(&cond, &Mut);
    }
    cout << "fun2 consumer called  -SharedVariable= " << SharedVariable << endl;
    pthread_mutex_unlock(&Mut);
    return NULL;
}


int main()
{
    pthread_t pthread1,pthread2;
    pthread_create(&pthread2,NULL,fun1,NULL);  //4 th argument is the argument passing to the fun1
    sleep(.1);
    pthread_create(&pthread1,NULL,fun2,NULL);

    pthread_join(pthread1,NULL);  //second argument is is a pointer to a location where the return value of the thread will be stored.
    pthread_join(pthread2,NULL);

    pthread_mutex_destroy(&Mut);
    pthread_cond_destroy(&cond);

    return 0;
}