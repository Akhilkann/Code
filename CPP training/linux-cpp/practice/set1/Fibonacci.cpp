#include<iostream>
using namespace std;

int main()
{
    cout << "Enter the limit" << endl;
    int limit = 0;
    int prev = 1, curr = 0,temp = 0;
    cin >> limit;
    if (limit == 1)
    {
        cout << 0 << endl;
    }
    else if ((limit >=2))
    {
        cout << 0 <<","<<1;
        for (int i = 0; i < limit-2; i++)
        {
            temp=prev;
            prev=curr+prev;
            curr=temp;
            cout<<","<<prev;
        }
        cout<<endl;
    }
}