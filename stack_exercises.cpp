#include <iostream>
#include <stack>
#include <string>

bool is_palindrome(std::string str) {
    std::stack<char> s;

    for (auto c : str) {
        s.push(c);
    }

    for (auto i = 0; i < str.size(); i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}

bool is_balanced(std::string str) {
    std::stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push('(');
        }
        else if (!s.empty() and str[i] == ')') {
            s.pop();
        }
        else if (s.empty() and str[i] == ')') {
            return false;
        }
    }
    return s.empty();
}

int main() {

    //std::string str1 = "pallap";
    //std::string str2 = "notpal";
    //std::string str3 = "racecar";
    //
    //std::cout << std::boolalpha << is_palindrome(str1) << std::endl;
    //std::cout << std::boolalpha << is_palindrome(str2) << std::endl;
    //std::cout << std::boolalpha << is_palindrome(str3) << std::endl;
    
    for (auto str : { "()", "(", ")", "(())", "(((()", "3 + 5*((8+4)-1" }) {
        std::cout << std::boolalpha << is_balanced(str) << std::endl;
    }

    return 0;
}
