#include <iostream>
#include <stack>
#include <vector>

void dec2bin(int n) {
    std::stack<int> binary;
    while (n > 0) {
        binary.push(n % 2);
        n = n / 2;
    }
    
    while (!binary.empty()) {
        std::cout << binary.top();
        binary.pop();
    }
    std::cout << std::endl;
}

bool ispal(std::string s) {
    std::stack<char> temp;
    for (auto c : s) {
        temp.push(c);
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != temp.top()) {
            return false;
        }
        temp.pop();
    }
    return true;
}

bool is_balanced(std::string s) {
    std::stack<char> temp;
    for (auto c : s) {
        if (c == '(') {
            temp.push(c);
        }
        else if (c == ')') {
            if (temp.empty()) {
                return false;
            }
            temp.pop();
        }
    }
    return temp.empty();
}

int main()
{
    //dec2bin(18);
    //std::cout << std::boolalpha << ispal("abcba") << std::endl;
    std::cout << std::boolalpha << is_balanced("4+5*((10)") << std::endl;

    return 0;
}
