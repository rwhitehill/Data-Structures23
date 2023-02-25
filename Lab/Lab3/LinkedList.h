#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

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

#endif
