// import functionality from other files
#include <iostream>

struct Node {
    int n;
    Node* next;

    Node(int n)
        : n{n}, next{nullptr}
    {}
};


// define NodePtr type
typedef Node* NodePtr;

// helper function to print out values in linked list (takes in head node)
void print_nodes(NodePtr head) {
    auto temp = head;
    while (temp != nullptr) {
        std::cout << temp->n << " "; 
        temp = temp->next;
    }
    std::cout << std::endl;
}

// takes in 2 linked list node pointers and returns node pointer to sorted
// linked list
NodePtr question1(NodePtr a, NodePtr b) {
    // initialize result node pointer and temp variable for iteration
    NodePtr ret = new Node(0);
    NodePtr temp = ret;

    // initialize temp variables for iterating through input linked lists
    NodePtr temp_a = a;
    NodePtr temp_b = b;
    // loop through linked lists while not at end of both
    while (temp_a != nullptr || temp_b != nullptr) {
        // if at end of either linked list just add all elements of 
        // other list to the end of res
        if (temp_a == nullptr) {
            temp->next = new Node(temp_b->n);
            temp_b = temp_b->next;
        }
        else if (temp_b == nullptr) {
            temp->next = new Node(temp_a->n);
            temp_a = temp_a->next;
        }
        // if not at end of either list: work through lists
        // compare current values of list --> add larger to res and update 
        // corresponding node pointer
        else {
            if (temp_a->n < temp_b->n) {
                temp->next = new Node(temp_a->n);
                temp_a = temp_a->next;
            }
            else {
                temp->next = new Node(temp_b->n);
                temp_b = temp_b->next; 
            }
            temp = temp->next;
        }
    }

    // return node pointer for sorted list (next node because of how
    // result was initialized)
    return ret->next;
}

// takes in node pointer for list and returns "sorted" list pointer
// sort: keep relative order but move odd numbers to front
NodePtr question2(NodePtr head) {
    // initialize result node pointer, temp for iteration,
    // and temp variable for iterating through input node pointer
    NodePtr ret = new Node(0);
    NodePtr temp = ret;
    NodePtr temp_head = head;

    // loop through input node pointer and append odd numbers to result list
    while (temp_head != nullptr) {
        if (temp_head->n % 2 == 1) {
            temp->next = new Node(temp_head->n);
            temp = temp->next;
        }
        temp_head = temp_head->next;
    }
   
    // reinitialize head node temp variable and repeat loop above but
    // for even numbers
    temp_head = head;
    while (temp_head != nullptr) {
        if (temp_head->n % 2 == 0) {
            temp->next = new Node(temp_head->n);
            temp = temp->next;
        }
        temp_head = temp_head->next;
    }
    
    // return next node in result node pointer (because of how it was
    // initialized)
    return ret->next;
}


int main() {

    // Question 1 example
    // input 1: { 1,3,5,7 }
    // input 2: { 2,4,6,8 }
    // expected output: { 1,2,3,4,5,6,7,8 }
    NodePtr a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);
    a->next->next->next = new Node(7);
    
    NodePtr b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);
    b->next->next->next = new Node(8);

    print_nodes(question1(a,b));

    std::cout << std::endl;

    // Question 2 example
    // input: { 1,2,5,8,3,6,7,4 }
    // expected output: { 1,5,3,7,2,8,6,4 }
    NodePtr c = new Node(0);
    NodePtr temp = c;
    for (auto i : { 1,2,5,8,3,6,7,4 }) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    c = c->next;

    print_nodes(question2(c));

    return 0;
}
