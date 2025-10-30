
#include <iostream>
using namespace std;

class Person {
public:
    string *name;

    // Constructor
    Person(string n) {
        name=new string;
        *name = n;
    }

    // Copy constructor
    // Person(const Person& p) {
    //     name = p.name;
    //     cout << "Copy constructor called!" << endl;
    // }

    void display() {
        cout << "Name: " << *name <<name<< endl;
    }
};

int main() {
    Person p1("Akhil");
    p1.display();
    Person p2 = p1;  // Copy constructor is called here

    p2.display();
    return 0;
}
