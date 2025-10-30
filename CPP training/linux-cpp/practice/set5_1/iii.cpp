#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define USING_SORT_ALGORITHM

using namespace std;

#ifdef USING_SORT_ALGORITHM
bool compareStrings(const char *str1, const char *str2);
#endif

void sortNames(char **ptr, int n);

int main()
{
    int n = 0;
    cout << "Enter the size of array" << endl;
    cin >> n;
    cin.ignore();
    char **ptr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        ptr[i] = new char[10];
        cout << "Enter " << i + 1 << ((i + 1 > 3) ? "th" : ((i + 1 == 1) ? "st" : ((i + 1 == 2) ? "nd" : "rd"))) << " name"<<endl;
        std::cin.getline(ptr[i], 10);
    }

    /*printing the array*/
    cout << "\nBefore sorting" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << ptr[j] << endl;
    }

    sortNames(ptr, n);
    /*after sorting*/
    cout << "\nAfter sorting" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << ptr[j] << endl;
    }
    delete (ptr);
    return 0;
}

void sortNames(char **ptr, int n)
{
#ifdef USING_SORT_ALGORITHM

    std::sort(ptr, ptr + n, compareStrings); // sort defined in #include <algorithm>

#else

    char s[10];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (ptr[j][0] > ptr[j + 1][0])
            {
                *s = ptr[j][0];
                ptr[j][0] = ptr[j + 1][0];
                ptr[j + 1][0] = *s;
            }
        }
    }

#endif
}

#ifdef USING_SORT_ALGORITHM
// Comparison function for sorting strings
bool compareStrings(const char *str1, const char *str2)
{
    return strcmp(str1, str2) < 0; // strcmp defined in #include<cstring>
}
#endif