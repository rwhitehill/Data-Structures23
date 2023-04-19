// Richard Whitehill
// Data Structures -- CS 400
// Homework 5
// 04/10/23

// import relevant functionality and data structures
#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

// function to order precedence of mathematical operators
int order(char c) {
    if (c == '+' or c == '-') {
        return 1;
    }
    if (c == '*' or c == '/') {
        return 2;
    }
    return 0;
}

// function to convert math expressions to postfix expressions
// NOTE: no validity checking -- assumes input expression is valid
std::string I2PConvertor(const std::string& infix_expr) {
    // initialize string for postfix expression and 
    // stack to hold operators and parentheses
    std::string post_expr;
    std::stack<char> storage;
    // loop over infix expression
    for (auto c : infix_expr) {
        // if letter variable --> push to postfix expression
        if (islower(c)) {
            post_expr += c;
        }
        // if opening parentheses --> push to stack
        else if (c == '(') {
            storage.push(c);
        }
        // if closing parentheses --> pop from stack and append to 
        // postfix expression until matching parentheses found (which is popped)
        else if (c == ')') {
            while (storage.top() != '(') {
                post_expr += storage.top();
                storage.pop();
            }
            storage.pop();
        }
        // if not letter or parentheses then char is operator
        // pop all higher order operators from stack and push
        // operator to stack
        else {
            while (!storage.empty() and order(storage.top()) >= order(c)) {
                post_expr += storage.top();
                storage.pop();
            }
            storage.push(c);
        }
    }
    // pop remaining operators from stack
    while (!storage.empty()) {
        post_expr += storage.top();
        storage.pop();
    }
    return post_expr;
}

int main() {
    // test cases
    std::string infix1 {"a*b+c"};
    std::string infix2 {"a-b*c"};
    std::string infix3 {"(a+b)/c"};
    std::string infix4 {"(a+b)*(c-d)"};
    // expected: ab*c+
    std::cout << I2PConvertor(infix1) << std::endl;
    // expected: abc*-
    std::cout << I2PConvertor(infix2) << std::endl;
    // expected: ab+c/
    std::cout << I2PConvertor(infix3) << std::endl;
    // expected: ab+cd-*
    std::cout << I2PConvertor(infix4) << std::endl;

    return 0;
}




