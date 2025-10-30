#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, loop = 1;
    enum Months
    {
        Jan,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct,
        Nov,
        Dec
    };
    int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(loop)
    {
        cout << "Enter a month" << endl;
        cin >> n;
        switch (n)
        {
        case Jan:
            cout << "Number of days in Jan is " << Days[Jan] << endl;
            break;
        case Feb:
            cout << "Number of days in Feb is " << Days[Feb] << endl;
            break;
        case Mar:
            cout << "Number of days in March is " << Days[Mar] << endl;
            break;
        case Apr:
            cout << "Number of days in April is " << Days[Apr] << endl;
            break;
        case May:
            cout << "Number of days in May is " << Days[May] << endl;
            break;
        case Jun:
            cout << "Number of days in June is " << Days[Jun] << endl;
            break;
        case Jul:
            cout << "Number of days in July is " << Days[Jul] << endl;
            break;
        case Aug:
            cout << "Number of days in August is " << Days[Aug] << endl;
            break;
        case Sep:
            cout << "Number of days in Sept is " << Days[Sep] << endl;
            break;
        case Oct:
            cout << "Number of days in Oct is " << Days[Oct] << endl;
            break;
        case Nov:
            cout << "Number of days in Nov is " << Days[Nov] << endl;
            break;
        case Dec:
            cout << "Number of days in Dec is " << Days[Dec] << endl;
            break;
        default:
            cout << "Invalid selection" << endl;
            loop = 0;
            break;
        }
    }
    return 0;
}