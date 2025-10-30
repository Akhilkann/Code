#include <iostream>
#include"node.h"

int main() {
    Node* n1 = new Node(10);
    n1->showNum();
        
    Node n2 = *n1;
    n2.showNum();
    
    delete n1;

    Node n3;
    n3 = n2;
    n3.showNum();
    return 0;
}
