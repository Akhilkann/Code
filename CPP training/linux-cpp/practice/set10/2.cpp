#include<iostream>
using namespace std;
class CMyArray
{
    int array[100];
    int NumOfElements;
    public:
    CMyArray(int n):NumOfElements(n){
        for(int i=0;i<n;i++)
        {
            array[i]=0;
        }
    }
    int& operator [](int index){return this->array[index];}

};

int main()
{
CMyArray mArray(10);
for(int i = 0; i < 10; i++)
{
mArray[i] = i;
}
for(int i = 0; i < 10; i++)
{
cout << endl << mArray[i];
}
for(int i = 0; i < 10; i++)
{
mArray[i]++;
}
for(int i = 0; i < 10; i++)
{
cout << endl << mArray[i];
}
}