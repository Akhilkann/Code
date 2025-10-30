#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<unistd.h>




int main()
{
    std::vector<int> SharedVector;

    std::mutex m1;
    std::condition_variable cv;

    int limit = 20;
    int turn = 1; // 1 for odd, 2 for even

    auto handler = [limit,&turn,&m1,&cv,&SharedVector](int start)
    {
        
        for(int i=start;i<=limit;i+=2)
        {
            std::unique_lock lck(m1);
            cv.wait(lck, [&turn,start](){ return turn==start; });

            SharedVector.push_back(i);
            if(start==1)
            {
                turn= 2; // switch to even
            }
            else
            {
                turn= 1; // switch to odd
            }
            cv.notify_one(); 
        }
    };

    std::thread thread1(handler,1);
    std::thread thread2(handler,2);

    thread1.join();
    thread2.join();

    std::cout<<"vector elements are:  ";
    for(auto i: SharedVector)
    {
        std::cout << i << " ";
    }

    std::cout<<std::endl<<"After reversing the vector: ";
    for(auto i=SharedVector.rbegin(); i!=SharedVector.rend(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}