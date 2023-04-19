// Richard Whitehill
// CS 400
// 03/27/23

// include relevant functionality from other files
#include <iostream>
#include <stack>
#include <string>
#include <vector>

// function to get user input postfix expressions
// quit on "-1" input
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

// function to determine if character is math operand
bool isoperand(char c) {
    std::string test = "+-*/";
    if (test.find(c) != std::string::npos) {
        return true;
    }
    else {
        return false;
    }
}

// function that evaluates postifix expressions
void eval_expressions(std::vector<std::string> expressions) {
    // initialize temporary variables to be operated on in intermediate steps
    int temp1;
    int temp2;
   
    // loop through input postfix expressions
    for (auto expr : expressions) {
        std::cout << "Postfix Expr: " << expr << ",";  
        std::stack<int> temp; // initialize stack for expressions evaluation
        bool valid = true;    // variable that keeps track of expression validity
        // loop through characters in expression
        for (auto i = 0; i < expr.length(); i++) {
            auto c = expr[i];
            // push char to stack if digit
            if (isdigit(c)) {
                temp.push(c - '0');
            }
            // evaluate intermediate expression if char is operand
            // check for underflow and if division by zero
            else if (isoperand(c)) {
                if (temp.empty()) {
                    std::cout << "INVALID" << std::endl;
                    valid = false;
                    break;
                }

                temp1 = temp.top(); 
                temp.pop();

                if (temp.empty()) {
                    std::cout << "INVALID" << std::endl;
                    valid = false;
                    break;
                }

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
                    if (temp1 == 0) {
                        std::cout << "INVALID (div by zero)" << std::endl;
                        valid = false;
                        break;
                    }
                    else {
                        temp.push(temp2 / temp1);
                    }
                }
            } 
        }
        // if not valid do nothing
        if (not valid) {
            continue;
        }
        // if empty stack --> invalid expression
        else if (temp.empty()) {
            std::cout << "INVALID" << std::endl; 
        }
        else {
            int result = temp.top();
            temp.pop();
            // valid expression --> output result
            if (temp.empty()) {
                std::cout << "evaluation result: " << result << std::endl;
            }
            // if stack not empty --> invalid expression
            else {
                std::cout << "INVALID" << std::endl;
            }
        } 
    }
}

int main() {
    // run expression getter and expression evaluator
    std::vector<std::string> expressions = get_expressions();
    eval_expressions(expressions);
    
    return 0;
}
