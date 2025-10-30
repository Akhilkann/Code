#include<iostream>
using namespace std;

class car
{
private:
    int a = 0;
    void prfn() { cout << a << endl; }

protected:
    void profn()
    {
        cout << a << endl;
        prfn();
    }

public:
    void pubfn()
    {
        cout << a << endl;
        profn();
    }
    car();
    ~car();
    static int u;
    const int y;
    int x = 0;

    static void print()
    {
        std::cout << "u=" << u << std::endl;
    }
};
int car::u = 2;
car::car() : y(u) { cout << "Const called" << endl; }
car::~car() { cout << "Dest called" << endl; }
class Derived : public car
{
public:
    int z;
    void profnct()
    {
        profn();
    }
    Derived();
    ~Derived();
};
Derived::Derived() : z(10) { cout << "Derived const" << endl; }
Derived::~Derived() { cout << "Derived dest" << endl; }

int main()
{
    car obj1;
    // obj1.prfn();
    // obj1.profn();
    // obj1.pubfn();
    Derived obj2;

    obj2.profnct();
    obj1.pubfn();

    return 0;
}