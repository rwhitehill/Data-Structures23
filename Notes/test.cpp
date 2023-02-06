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

int main() {
    std::vector<int> vi1 = { 10,20,30 }; //,40,50,80,100,120 };
    int target = 20;

    //std::cout << binarySearch(vi1,target) << std::endl;
    //std::cout << binarySearch({},target)  << std::endl;

    return 0;
}
