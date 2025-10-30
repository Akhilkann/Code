#include <iostream>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include <bits/stdc++.h>
using namespace std;

//#define DEQUE 
//#define LIST 
#define FORWARD_LIST 


int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}


int main(void)
{
    int var=2;
#if defined DEQUE

    deque<int> x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(10);
    auto it=x.begin()+1;
    x.insert(it,5);
    x.insert((x.begin()+2),44);
    x.erase(x.begin()+3);
    for(auto i:x)
    {
        cout<<i<<" ";
    }
    cout<<x[3];  //to access 3rd element

#elif defined LIST
    list<int> y;
    y.push_front(1);
    y.push_back(2);
    y.push_back(3);
    y.push_front(22);
    auto it=y.begin();
    advance(it,3);
    y.insert(it,5);
    
    for(auto i:y)
    {
        cout<<i<<" ";
    }

    cout<<endl<<*next(y.begin(),2);  //accessing the elments in 2nd position 

    /*updating values*/
    auto it1=y.begin();
    advance(it1,1);  //update value in position 3
    *it1=4;   //update value with 4

    cout<<endl;
    
     for(auto i:y)
    {
        cout<<i<<" ";
    }

    /*Erase an element*/
    auto it2=y.begin();
    advance(it2,1);  //update value in position 1
    y.erase(it2);

    cout<<endl;
    
     for(auto i:y)
    {
        cout<<i<<" ";
    }

#elif defined FORWARD_LIST

    forward_list<int> z;
    z={1,2,3,4,5};
    for(auto i:z)
    {
        cout<<i<<" ";
    }
    z.push_front(6);

    cout<<endl;
     for(auto i:z)
    {
        cout<<i<<" ";
    }

    /*update element in position 3*/
    auto it=next(z.begin(),3);
    *it=8;

    cout<<endl;
     for(auto i:z)
    {
        cout<<i<<" ";
    }

    /*Remove element in pos 4*/
    auto it1=next(z.begin(),3);

    z.erase_after(it1);  //erase after 3 to delete 4 th element.

    cout<<endl;
     for(auto i:z)
    {
        cout<<i<<" ";
    }
     
    /*OR*/
    auto it2=z.begin();
    advance(it2,3);
    z.erase_after(it2);
    cout<<endl;
     for(auto i:z)
    {
        cout<<i<<" ";
    }


    /*Find an element*/

    auto it3=find(z.begin(),z.end(),8);
    cout<<endl<<*it3;



#endif
    return 0;
}