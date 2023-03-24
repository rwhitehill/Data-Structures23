#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>

std::vector<std::string> get_expressions() {
    std::vector<std::string> container;
    std::string temp;
    while (true) {
        std::getline(std::cin,temp);
        if (temp == "-1") {
            break;
        }
        else {
            container.push_back(temp);
        }
    }
    return container;
}

bool isoperand(char c) {
    std::string test = "+-*/";
    if (test.find(c) != std::string::npos) {
        return true;
    }
    else {
        return false;
    }
}

void eval_expressions(std::vector<std::string> expressions) {
    int temp1;
    int temp2;
    std::stack<int> temp;
    for (auto expr : expressions) {
        std::cout << "Postfix Expr: " << expr << ", evaluation result: ";
        for (auto c : expr) {
            if (isdigit(c)) {
                temp.push(c - '0');
            }
            else if (isoperand(c)) {
                temp1 = temp.top();
                temp.pop();
                temp2 = temp.top();
                temp.pop();

                if (c == '+') {
                    temp.push(temp2 + temp1);
                }
                else if (c == '-') {
                    temp.push(temp2 - temp1);
                }
                else if (c == '*') {
                    temp.push(temp2 * temp1);
                }
                else {
                    temp.push(temp2 / temp1);
                }
            }
        }
        
        std::cout << temp.top() << std::endl;
    }
}

int main() {
    std::vector<std::string> expressions = get_expressions();
    eval_expressions(expressions);
    
    //std::cout << std::boolalpha << isoperand("r") << std::endl;
}
