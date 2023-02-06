# Data Structures - Lecture 5 (02/01/23)

Example code with vectors (search):
````C++

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

````

### Notes about vectors in C++

**contiguous**: refers to the storage locations for elements (elements can be accessed using offsets on regular pointers to is elements)

**sequential**: elements are ordered in a strict linear sequence and are accessed by their position in this sequence

Operations on vectors: time
* push_back(): O(1)
* pop(): O(1)
* access any element by index (with [] operator or at()): O(1)
* insert at arbitrary location: O(N)
* erase at arbitrary location: O(N)
    * linear time because vectors are contiuguous and sequential (adding or removing in the middle of a vector causes elements to have to be shifted in memory)

### Initializing vectors

````C++
std::vector<int> get_unique(const std::vector<int>& vi) {
    std::vector<int> unique;

    for (auto i : vi) {
        if (std::find(unique.begin(),unique.end(),i) == unique.end()) {
           unique.push_back(i);
        }
    }
    return unique;
}

int main() 
{
    std::vector<int> vi(4,100); // vector with 4 copies of 100
    std::vector<int> vi2{4,100};

    // print all elements from vi
    for (auto i : vi) {
        std::cout << i << " " << std::endl;
    }

    vi = {100,20,30,1,5,100,5,25};

    // ex 2: count how many occurrences of target are in the vector
    // e.g. there is 1 occurrence of 30 in vi

    // write a function that takes in a vector and returns
    // another vector with only unique numbers

    return 0;
}



````



