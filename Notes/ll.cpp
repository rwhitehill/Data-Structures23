#include <iostream>

struct Node {
    int n;
    Node* next;

    Node(int n)
        : n{n}, next{nullptr}
    {}
};

typedef Node* NodePtr;

class LinkedList {
private:
    NodePtr _head{nullptr};
public:
    LinkedList() = default;

    ~LinkedList() {
        // TODO: implement dtor for LL
    }
    
    void add_at_head(int n) {
        // 1. create a new node
        NodePtr tempNode = new Node(n);
        // 2. link the new node to the rest of the LL
        tempNode->next = _head;
        // 3. update head
        _head = tempNode;
    }

    void traverse() const {
        auto temp = _head;
        while (temp != nullptr) {
            std::cout << temp->n << " ";
            temp = temp->next;
        }
    }
};

int main() 
{ 
    LinkedList ll;    
    for (auto i : {11,22,33,44}) {
        ll.add_at_head(i);
    }
    ll.traverse();
}
