#include <iostream>
#include <vector>

std::vector<int> get_unique(const std::vector<int>& vi) {
    std::vector<int> unique {};

    for (auto i : vi) {
        if (std::find(unique.begin(),unique.end(),i) == unique.end()) {
           unique.push_back(i);
        }
    }
    return unique;
}

int main()
{
    std::vector<int> vi {8,5,1,2,1,3,1,4,2,5,6,8};

    std::vector<int> unique = get_unique(vi);
    for (auto i : unique) {
        std::cout << i << " ";
    }

    return 0;
}

