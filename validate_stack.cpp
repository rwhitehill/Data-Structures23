#include <iostream>
#include <vector>
#include <stack>

bool validate(std::vector<int>& pushed, std::vector<int>& popped) {
    int i = 0;
    std::stack<int> storage;
    for (auto x : pushed) {
        storage.push(x);
        while (!storage.empty() and storage.top() == popped[i]) {
            storage.pop();
            i++;
        }
    }
    return storage.empty();
    //while (j != popped.size()) {
    //    if (storage.empty()) {
    //        if (i >= pushed.size()) {
    //            return false;
    //        }
    //        storage.push(pushed[i]);
    //        i++;
    //        continue;
    //    }

    //    if (!storage.empty() and storage.top() != popped[j]) {
    //        if (i >= pushed.size()) {
    //            return false;
    //        }
    //        storage.push(pushed[i]);
    //        i++;
    //        continue;
    //    }
    //    else {
    //        storage.pop();
    //        j++;
    //    }
    //}
    //return true;
}

int main()
{

    std::vector<int> pushed { 1,2,3,4,5 };
    std::vector<int> popped { 3,4,1,5,2 };

    std::cout << std::boolalpha << validate(pushed,popped) << std::endl;

    return 0;
}
