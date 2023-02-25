#include <iostream>
//#include <algorithm>
#include "Node.h"
#include "LinkedList.h"

typedef Node* NodePtr;

NodePtr question1(NodePtr a, NodePtr b) {
    NodePtr ret;
    NodePtr temp = ret;

    NodePtr temp_a = a;
    NodePtr temp_b = b;
    while (temp_a != nullptr || temp_b != nullptr) {
        if (temp_a == nullptr) {
            std::cout << temp_b->n << " ";
            temp_b = temp_b->next;
        }
        else if (temp_b == nullptr) {
            std::cout << "yes" << std::endl;
            std::cout << temp_a->n << " ";
            temp_a = temp_a->next;
        }
        else {
            if (temp_a->n < temp_b->n) {
                std::cout << temp_a->n << " ";
                temp_a = temp_a->next;
            }
            else {
                std::cout << temp_b->n << " ";
                temp_b = temp_b->next; 
            }
        }
    }
    return nullptr;
}

int main() {
    NodePtr a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);
    a->next->next->next = new Node(7);
    
    NodePtr b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);
    b->next->next->next = new Node(8);

    question1(a,b);

    return 0;
}
