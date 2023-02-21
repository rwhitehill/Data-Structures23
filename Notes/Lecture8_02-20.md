# Data Structures - Lecture 8 (02/20/23)

Destructor for LL:
````C++

~LinkedList() {
    while (_head) {
        auto temp = _head;
        _head = _head->next;
        delete temp;
    }
}

````

recursive search for target in LL
````C++

NodePtr searchR(NodePtr p,int target) {
    return _searchR(p,target);
}

NodePtr _searchR(NodePtr p, int target) {
    if (!p) return nullptr;
     
}

````

delete target in LL
````C++

void delR(int target) {
    _delR(_head,target);
}

void _delR(NodePtr p, int target) {
    if (!p) return;
    if (p && p->n == target) {
        auto temp = p->next;
        delete p;
        return temp;
    }
    p->next = _delR(p->next,target);
    return p;
}

````




