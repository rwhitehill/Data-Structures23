#include <iostream>
#include "Node.h"
#include "LinkedList.h"

typedef Node* NodePtr;

void print_nodes(NodePtr head) {
    auto temp = head;
    while (temp != nullptr) {
        std::cout << temp->n << " "; 
        temp = temp->next;
    }
    std::cout << std::endl;
}

NodePtr question1(NodePtr a, NodePtr b) {
    NodePtr ret = new Node(0);
    NodePtr temp = ret;

    NodePtr temp_a = a;
    NodePtr temp_b = b;
    while (temp_a != nullptr || temp_b != nullptr) {
        if (temp_a == nullptr) {
            //std::cout << temp_b->n << " ";
            temp->next = new Node(temp_b->n);
            temp_b = temp_b->next;
        }
        else if (temp_b == nullptr) {
            //std::cout << temp_a->n << " ";
            temp->next = new Node(temp_a->n);
            temp_a = temp_a->next;
        }
        else {
            if (temp_a->n < temp_b->n) {
                //std::cout << temp_a->n << " ";
                temp->next = new Node(temp_a->n);
                temp_a = temp_a->next;
            }
            else {
                //std::cout << temp_b->n << " ";
                temp->next = new Node(temp_b->n);
                temp_b = temp_b->next; 
            }
            temp = temp->next;
        }
    }
    return ret->next;
}

NodePtr question2(NodePtr head) {
    NodePtr ret = new Node(0);
    NodePtr temp = ret;
    NodePtr temp_head = head;

    while (temp_head != nullptr) {
        if (temp_head->n % 2 == 1) {
            temp->next = new Node(temp_head->n);
            temp = temp->next;
        }
        temp_head = temp_head->next;
    }
    
    temp_head = head;
    while (temp_head != nullptr) {
        if (temp_head->n % 2 == 0) {
            temp->next = new Node(temp_head->n);
            temp = temp->next;
        }
        temp_head = temp_head->next;
    }

    return ret->next;
}


int main() {

    // Question 1 example
    NodePtr a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);
    a->next->next->next = new Node(7);
    
    NodePtr b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);
    b->next->next->next = new Node(8);

    print_nodes(question1(a,b));

    // Question 2 example
    NodePtr c = new Node(0);
    NodePtr temp = c;
    for (auto i : { 1,2,5,8,3,6,7,4 }) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    c = c->next;

    print_nodes(question2(c));
    print_nodes(c);

    return 0;
}
