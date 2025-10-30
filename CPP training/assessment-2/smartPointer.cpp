#include<iostream>

namespace MyStd{
template<typename T>
class unique_ptr {
    T* ptr;
public:
    unique_ptr(T* p) : ptr(p) {
        if (ptr) {
            std::cout << "UP initialized: " << ptr << std::endl;
        } else {
            std::cout << "UP is null" << std::endl;
        }
    }
    ~unique_ptr() { delete ptr; }    

    unique_ptr(unique_ptr& a) = delete;

    unique_ptr(unique_ptr&& a): ptr(a.ptr) {std::cout << "UP Move constructor called " << std::endl;
        a.ptr = nullptr; 
    }

    T* operator->() const { return ptr; }

};

template<typename T>
class shared_ptr {
    T* ptr;
    int* ref_count;
public:
    shared_ptr(T* p) : ptr(p), ref_count(new int(1)) {
        if (ptr) {
            std::cout << "SP initialized: " << ptr <<" Reference count: " << *ref_count<< "  "<<ref_count<<std::endl;
        } else {
            std::cout << "SP is null" << std::endl;
        }
    }

    shared_ptr(shared_ptr& a) : ptr(a.ptr), ref_count(a.ref_count) {
        ++(*ref_count);
        std::cout << "SP Copy constructor called. Reference count: " << *ref_count <<"  "<<ref_count<< std::endl;
    }
    shared_ptr(shared_ptr&& a) : ptr(a.ptr), ref_count(a.ref_count) {
        a.ptr = nullptr;
        //a.ref_count = nullptr;
        std::cout << "SP Move constructor called. Reference count:" << *ref_count << "  "<<ref_count<<std::endl;
    }

    ~shared_ptr() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
            std::cout << "Pointer deleted and reference count is zero." << std::endl;
        }
    }

    int use_count(){return *ref_count;}

    T* operator ->(){return ptr;}

};

}

class temp{
    int x;
public:
    temp(int a):x(a){std::cout<<"temp constructor called"<<std::endl;}
    ~temp(){}

    void display() { std::cout << "Value: " << x << std::endl; }

};

int main()
{
    MyStd::unique_ptr<temp> up1(new temp(10));
    MyStd::unique_ptr<temp> up2 = std::move(up1); 
    up2->display(); 

    MyStd::shared_ptr<temp> sp1(new temp(20));
    MyStd::shared_ptr<temp> sp2 = sp1;
    MyStd::shared_ptr<temp> sp3 = std::move(sp1);

    sp2->display();
    std::cout<<"SP count= "<< sp1.use_count()<<std::endl;

    std::cout<<"end of program"<<std::endl;
    return 0;
}