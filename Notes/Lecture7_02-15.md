# Data Structures - Lecture 6 (02/08/23)

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
        NodePtr curr = head;
        while (curr != nullpty) {
            Nodeptr temp = curr;
            curr = curr->next;
            delete temp;
        }
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

    NodePtr search(int target) const {
        auto temp{ _head };

        while (temp) {
            if (temp->n == target) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
   
    // TODO
    NodePtr recursive_search(int target) const {
        auto temp { _head };
    }

    void del(int target) {
        // case 1: LL is empty
        if (empty()) return;
        
        // case 2: head node to be deleted
        if (_head && _head-> == target) {
            auto temp = _head;
            _head = _head->next;
            delete temp;
            return;
        }
        
        // case 3: check non-head nodes
        NodPtr prev = nullptr;
        NodePtr curr = _head;
        while (curr && curr-> != target) {
            prev = curr;
            curr = curr->next;
        }
        // after this while loop
        // either 1) the curr is nullpty, exclusively 
        // or 2) curr's value is the target

        // case 4
        if (curr == nullptr) {
            return;
        }

        // case 3 continued
        // note that prev is not nullptr at this place
        prev->next = curr->next
        delete curr;
    }
};

int main() 
{ 
    // LinkedList ll;    
    // for (auto i : {11,22,33,44}) {
    //     ll.add_at_head(i);
    // }
    // ll.traverse();

     

    return 0;

}

````



