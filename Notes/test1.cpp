#include <iostream>
#include <vector>
#include <algorithm>

// regular linear search
int linearSearch1(const std::vector<int>& vi, int target) {
    for (auto i = 0; i < vi.size(); i++) {
        if (vi[i] == target) {
            return i;
        }
    }
    return -1;
}

// linear search (with pointer to elements instead of simple index)
int linearSearch2(const std::vector<int>& vi, int target) {
    for (auto it = vi.begin(); it != vi.end(); it++) {
        if (*it == target) {
            return it - vi.begin();
        }
    }
    return -1;
}

// linear search (with std::find)
int linearSearch3(const std::vector<int>& vi, int target) {
    auto it = std::find(vi.begin(),vi.end(),target);
    if (it != vi.end()) {
        return it - vi.begin();
    }
    return -1;
}

int _linearSearchR(const std::vector<int> vi, int index, int target);

// linear search (with recursion)
int linearSearch4(const std::vector<int>& vi, int target) {
    return _linearSearchR(vi,0,target);
}


int main()
{
    
    std::vector<int> vi{ 100,20,30,1,5,100,5,25 };
    std::cout << linearSearch1(vi,30) << std::endl;
    std::cout << linearSearch2(vi,30) << std::endl;
    std::cout << linearSearch3(vi,30) << std::endl;
    std::cout << linearSearch4(vi,30) << std::endl;

    return 0;

}

int _linearSearchR(const std::vector<int> vi, int index, int target) {
    if (index >= vi.size()) {
        return -1;
    }
    else if (vi[index] == target) {
        return index;
    }
    return _linearSearchR(vi,index+1,target);
}
