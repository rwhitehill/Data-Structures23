# Data Structures - Lecture 4 (01/30/23)

### Binary search

Make sure to run command `g++ -std=c++11 <filename>` for compilation on mac

````C++

#include <iostream>
#include <vector>

// Pre-condition: the search range must be sorted
// running binary search on unsorted range could return incorrect answer
// ret: a valid index if target is found in vi.
//      -1 if not found in vi
int binarySearch(const std::vector<int>& vi, int target) {
    if (vi.empty()) {
        return -1;
    }

    int low  = 0;
    int high = vi.size() - 1;
    
    while (low <= high)  {
        int mid = low + (high - low) / 2;
        if (vi[mid] == target) {
            return mid;
        }
        else if (vi[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// binary search recursive version
int binarySearchR(const std::vector<int>& vi, int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low)/2;
    if (vi[mid] == target) {
        return mid; 
    }
    else if (vi[mid] < target) {
        return binarySearchR(vi,mid+1,high,target);
    }
    else {
        return binarySearchR(vi,low,mid-1,target);
    }
}

int main() {
   
    std::vector<int> vi1 = { 10,20,30,40,50,80,100,120 };
    auto target = 20;

    std::cout << binarySearch(vi1,target) << std::endl;
    std::cout << binarySearch({},target)  << std::endl;
    std::cout<< binarySearch(vi1,21)      << std::endl;

    std::cout << binarySearch(vi1,0,vi1.size(),30) << std::endl;
    std::cout << binarySearch({},0,vi1.size(),120) << std::endl;
    std::cout<< binarySearch(vi1,0,vi1.size(),60)  << std::endl;

    return 0;
}

````
