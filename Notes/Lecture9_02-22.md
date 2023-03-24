# Data Structures - Lecture 9 (02/22/23)

New data structure: *stack*
* LIFO: last in, first out

1) convert dec number to binary number
2) palindrome string
3) parentheses validation
4) postfix expression evaluation
5) infix expression to postfix conversion
6) stack sequence validation
7) permutation
8) [optional] the eight-queen problem

Stack operations:
- push: add one element as the new top element to the stack
- pop: remove the top element without return
- top: return but not remove the top element 
- empty: 
- size: return the number of elements in a stack

example of stack implementation:
````C++

#include <iostream>
#include <vector>

template <class T>
class MyStackV {
private:
    std::vector<T> _v;
public:
    MyStackV() = default;

    bool empty () const { return _v.empty(); }
    size_t size() const { return _v.size(); }
    void push(T t) { _v.push_back(v); }
    void pop() { _v.pop_back(); }
    T& top() { return _V.back(); }
    const T& top() const { return _v.back(); }
};

bool isPal(const std::string& s) {
    MyStackV<char> st;
    for (auto ch : s) {
        st.push(ch);
    }

    std::stringstream ss;
    while (!st.empty()) {
        ss << st.top();
        st.pop();
    }

    return ss.str() == s;
}

int main()
{

    MyStackV<int> msi;
    for (auto i : { 10, 20, 30, 40 }) {
        msi.push(i) 
    }

    while (!msi.empty()) {
        std::cout << msi.top() << " ";
        msi.pop();
    }

    // app1: dec -> bin
    int number = 143;
    while (number) {
        msi.push(number % 2);
        number /= 2;
    }
    
    while (!msi.empty()) {
        std::cout << msi.top() << " ";
        msi.pop();
    }

    // app2: check if a string is palindrome or not
    std::string s1 = "abcdedcba";
    std::string s2 = "madamimadam";
    std::string s3 = "samsung";

    return 0;
}

````





