// Richard Whitehill
// Data Structures - CS 400
// Lab 2

// include functionality from cpp files
#include <iostream>
#include <vector>
#include <algorithm>

// Question 1: Determine if vector can be used as a set
// loops through vector to determine if all the elements are unique
// if unique --> return true, otherwise false
bool vec_is_a_set(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (std::find(vec.begin()+i+1,vec.end(),vec[i]) != vec.end()) {
            return false;
        }
    }
    return true;
}

// Question 2: Define basic set operations
// initialize union as vector 1 and loop through vector 2 to add
// elements in vector 2 which are not in vector 1
std::vector<int> set_union(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> temp = v1;
    for (int i = 0; i < v2.size(); i++) {
        if (std::find(v1.begin(),v1.end(),v2[i]) == v1.end()) {
            temp.push_back(v2[i]);
        }
    }
    return temp;
}

// initialize intersection as empty vector and loop through vector 1
// and search vector 2 for matching elements, which are appended 
// to the intersection
std::vector<int> set_intersection(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> temp;
    for (int i = 0; i < v1.size(); i++) {
        if (std::find(v1.begin(),v1.end(),v1[i]) != v1.end() && std::find(v2.begin(),v2.end(),v1[i]) != v2.end()) {
            temp.push_back(v1[i]);
        }
    }
    return temp;
}

// initialize difference as empty, loop through vector 2 and search 
// for common elements --> if not common, then append difference set
std::vector<int> set_difference(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> temp;
    for (int i = 0; i < v1.size(); i++) {
        if (std::find(v2.begin(),v2.end(),v1[i]) == v2.end()) {
            temp.push_back(v1[i]);
        }
    }
    return temp;
}

// helper function to print generic vector elements
void print_vec(std::vector<int>& vec){
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Question 1 test
    std::vector<int> vec1 = {1,4,5,6,9};
    std::vector<int> vec2 = {1,4,5,6,1};
    std::cout << vec_is_a_set(vec1) << std::endl;
    std::cout << vec_is_a_set(vec2) << std::endl;

    std::cout << std::endl;

    //Question 2 test
    std::vector<int> vector1 = {1,2,3,4};
    std::vector<int> vector2 = {2,4,5,6};

    std::vector<int> join = set_union(vector1,vector2);
    print_vec(join);
    
    std::vector<int> inter = set_intersection(vector1,vector2);
    print_vec(inter);

    std::vector<int> diff12 = set_difference(vector1,vector2);
    print_vec(diff12);

    std::vector<int> diff21 = set_difference(vector2,vector1);
    print_vec(diff21);


    return 0;
}
