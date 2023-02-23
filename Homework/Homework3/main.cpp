#include <iostream>
#include "Node.h"
#include "LinkedList.h"

typedef Node* NodePtr;

//NodePtr question1(NodePtr a, NodePtr b) {
//    
//}

int main() {
    Node a {1};
    a.next = new Node(3);
    a.next->next = new Node(5);
    a.next->next->next = new Node(7);
    a.next->next->next->next = new Node(9);

    auto temp = a;
    while (temp.next != nullptr) {
        std::cout << temp.n << " ";
        temp = *temp.next;
    }

    return 0;
}
