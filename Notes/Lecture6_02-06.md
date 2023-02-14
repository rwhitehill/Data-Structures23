# Data Structures - Lecture 6 (02/06/23)

Define a function that takes a vector of ints and times 2 to each number.
* e.g.: {10,20,30} --> {20,40,60}
````C++
int x2(int n) { 
    return n *= 2;
}

void times_two(std::vector<int>& vi) {
    std::transform(vi.begin(),vi.end(),vi.begin(),x2)
}

void print_vector(const std::vector<int>& vi) {
    for (auto i : vi) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

````
