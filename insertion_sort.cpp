#include <iostream>
#include <vector>

template <class T>
void print_vector(const std::vector<T>& vec) {
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> insertion_sort(std::vector<int>& vec) {
    int temp;
    int pos;
    for (auto i = 0; i < vec.size(); i++) {
        temp = vec[i];
        pos  = i;
        while (pos > 0 && vec[pos-1] > temp) {
            vec[pos] = vec[pos-1];
            pos -= 1;
        }
        vec[pos] = temp;
    }
    return vec;
}

int main() 
{

    std::vector<int> vec { 8,1,5,3,9,4,7,0,6,2 };
    print_vector(insertion_sort(vec));

    return 0;
}






