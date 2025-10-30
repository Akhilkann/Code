
/*
How it works:

    A base class declares a virtual function.
    A derived class inherits from the base class and provides a new implementation of the virtual function, using the same signature.
    When the function is called through a pointer or reference to a base class object that actually refers to a derived class object, the derived class's version of the function is executed.

*/
#include<iostream>

using namespace std;

class Vehicle
{
public:
    virtual void TyreNos() { cout << "Vehicle number of tyre will channge depending on the type" << endl; }  //The function in the base class must be declared as virtual. This allows the compiler to determine which version of the function to call at runtime.
};

class Bike : public Vehicle
{
public:
    int tyreNo = 2;
    void TyreNos() override { cout << "bike have " << tyreNo << " tyres" << endl; }
};

class Car : public Vehicle
{
public:
    int tyreNo = 4;
    void TyreNos() override { cout << "Car have " << tyreNo << " tyres" << endl; }
};

class Bus : public Vehicle
{
public:
    int tyreNo = 6;
    void TyreNos() override { cout << "Bus have " << tyreNo << " tyres" << endl; }
};

int main()
{

    Vehicle *A = new Vehicle;
    Vehicle *B = new Bike;
    Vehicle *C = new Car;
    Vehicle *D = new Bus;

    A->TyreNos();
    B->TyreNos();
    C->TyreNos();
    D->TyreNos();

    delete (A);
    delete (B);
    delete (C);
    delete (D);

    return 0;
}

