#include <iostream>
#include <vector>
#include <stack>

bool validate(std::vector<int>& pushed, std::vector<int>& popped) {
    int i = 0; // index for popped
    std::stack<int> storage;
    for (auto x : pushed) {
        storage.push(x);
        while (!storage.empty() and storage.top() == popped[i]) {
            storage.pop();
            i++;
        }
    }
    return storage.empty();
}

int main() {
    std::vector<int> v1 { 1,2,3,4,5 };
    std::vector<int> v2 { 3,1,4,5,2 };

    std::cout << std::boolalpha << validate(v1,v2) << std::endl;
}
