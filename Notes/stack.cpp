#include <iostream>
#include <string>
#include <sstream>
#include <list>

template <class T>
class MyStackLL {
private:
    std::list<T> _list;
public:
    MyStackLL() = default;

    bool empty() const { return _list.empty(); }
    size_t size() const { return _list.size(); }
    void push(T t) { _list.push_back(t); }
    void pop() { _list.pop_back(); }
    T& top() { return _list.back(); }
    const T& top() const { return _list.back(); }
    
};

bool isBalanced(const std::string& str) {
    MyStackLL<char> st;

    // scan each ch from str,
    // // push if (, or ...
    for (auto ch : str) {
        if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')' && !st.empty() && st.top() == '(') {
            st.pop(); 
        }
        else {
            return false;
        }
    }

    return st.empty();
}

int main() {
   
    std::string s11 = "()()(())";
    std::string s22 = "(()";
    std::string s33 = ")";

    std::cout << std::boolalpha << isBalanced(s11) << std::endl;
    std::cout << std::boolalpha << isBalanced(s22) << std::endl;
    std::cout << std::boolalpha << isBalanced(s33) << std::endl;


    return 0;
}
