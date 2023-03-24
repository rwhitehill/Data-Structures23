#include <iostream>
#include <vector>

template <class T>
class Stack {
private:
    std::vector<T> _stack;
public:

    Stack() = default;

    void push(const T& entry) { _stack.push_back(entry); }
    void pop() { _stack.pop_back(); }
    T& top() { return _stack.back(); }
    const T& top() const { return _stack.back(); }
    bool empty() const { return _stack.empty(); }
    size_t size() const { return _stack.size(); }

};

int main() {

    Stack<int> s;

    for (auto i : { 1,2,3,4 }) {
        s.push(i);
    }

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}
