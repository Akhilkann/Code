#include<iostream>

using namespace std;


int main()
{
    int input = 0, flag = 0,loop = 1;
    cout<<"Enter 0 to exit the execution"<<endl;
    while (loop)
    {
        cout << "Enter a number " << endl;
        cin >> input;
        if (input >= 1)
        {
            for (int i = 2; i < (input); i++)
            {
                if ((input % i) == 0)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << input << " is not a prime number" << endl;
                flag=0;
            }
            else
            {
                cout << input << " is a prime number" << endl;
            }
        }
        else
        {
            loop = 0;
        }
    }

    return 0;
}