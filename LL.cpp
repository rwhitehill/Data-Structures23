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
        NodePtr curr = _head;
        while (curr != nullptr) {
            NodePtr temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void add_at_head(int n) {
        NodePtr tempNode = new Node(n);
        tempNode->next = _head;
        _head = tempNode;
    }

    void add_at_tail(int n) {
        // if LL is empty
        if (!_head) {
            add_at_head(n);
            return;
        }
        auto temp = _head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(n);
    }

    void traverse() const {
        auto temp = _head;
        while (temp != nullptr) {
            std::cout << temp->n << " @" << temp << std::endl;
            temp = temp->next;
        }
    }

    bool empty() const { return !_head; }

    NodePtr search(int target) const {
        auto temp{ _head };
        while (temp) {
            if(temp->n == target) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    NodePtr search_R(int target) {
        auto temp { _head };
        return _search_R(_head,target);
    }

    NodePtr _search_R(NodePtr node,int target) {
        if (node->n == target) {
            return node;
        }
        return _search_R(node->next,target);
    }

    void del(int target) {
        if (empty()) return;

        if (_head && _head->n == target) {
            auto temp = _head;
            _head = _head->next;
            delete temp;
            return;
        }

        NodePtr prev; //= nullptr;
        NodePtr curr = _head;
        while (curr && curr->n != target) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            return;
        } 
        prev->next = curr->next;
        delete curr;
    }

    void del_at_head() {
        del(_head->n);
    }

};

int main() {

    LinkedList LL;
    std::cout << "Empty: " << LL.empty() << std::endl;
    for (auto i : { 1,2,3,4,1 }) {
        LL.add_at_tail(i);
    }
    LL.traverse();
    std::cout << "Empty: " << LL.empty() << std::endl;

    std::cout << LL.search(1) << std::endl;
    std::cout << LL.search(10) << std::endl;
    std::cout << LL.search_R(3) << std::endl;

    //LL.del(2);
    LL.del_at_head();
    LL.traverse();

    return 0;   
}
