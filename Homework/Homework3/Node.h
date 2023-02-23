#ifndef NODE_H
#define NODE_H

struct Node {
    int n;
    Node* next;

    Node(int n)
        : n{n}, next{nullptr}
    {}
};

#endif
