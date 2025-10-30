#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t sem1;
int value =0;

void* SharedFun(void* x)
{
    for(int i=0;i<5;i++)
    {
    sem_wait(&sem1);
    value++;
    std::cout<<"Entered critical section fun"<<*(int*)x<<"value: "<<value<<std::endl;
    sem_post(&sem1);
    sleep(.1);
    }
    return NULL;
}



int main()
{
    pthread_t T1,T2;
    sem_init(&sem1,0,1);

    int x=1,y=2;
    pthread_create(&T1,NULL,SharedFun,(void*)&x);
    pthread_create(&T2,NULL,SharedFun,(void*)&y);

    pthread_join(T1,NULL);
    pthread_join(T2,NULL);

    std::cout<<"main"<<std::endl;
    sem_destroy(&sem1);

    return 0;
}