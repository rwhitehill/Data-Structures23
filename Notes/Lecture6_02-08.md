# Data Structures - Lecture 6 (02/08/23)

### Vectors
$O(1)$ operations:
* `push_back()`
* `pop_back()`
* `size()`
* 'empty()'

$O(N)$ operations:
* `insert()`
* `erase()`
* `traverese()`

### Linked Lists (based on singly linked lists)

operations and time scales
* `add_at_head()`: $O(1)$
* `del_at_head()`: $O(1)$
* if no tail pointer: 
    * `add_at_tail()`: $O(N)$
    * `del_at_tail()`: $O(N)$
* for general `del_node`: $O(?)$
* `traverse()`: $O(N)$

linked lists (LL) do not maintain any index and instead the pattern "go to next" will be seen multiple times in LL

What is a linked list: an empty list with one node followed by another linked list
* note the recursion here

````C++

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

    void add_at_tail(int n) {
        // special case when LL is empty
        if (!_head) {
            add_at_head(n);
            return;
        }
        // when LL is not empty 
        auto temp = _head;
        while (temp && temp->next) {
            temp = temp->next;
        }

        // after the while loop, temp should be pointing at the last node
        // so create a new node and assign its address to temp->next
        temp->next = new Node(n);
    }

    void traverse() const {
        auto temp = _head;
        while (temp != nullptr) {
            std::cout << temp->n << " @" << temp << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    bool empty() const { return _head; }
};

int main() 
{ 
    LinkedList ll;    
    for (auto i : {11,22,33,44}) {
        ll.add_at_head(i);
    }
    ll.traverse();
}

````



