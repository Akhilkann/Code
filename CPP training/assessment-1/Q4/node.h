#include<iostream>
// Class declaration
class Node {
    int *ptr;

public:
    Node() {}
    Node(int val) : ptr(new int)
    {
        *ptr = val;
    }
    Node(Node &a) : ptr(new int)
    {
        ptr = a.ptr;
    }

    void showNum();

    ~Node() { ptr = nullptr; }
};
