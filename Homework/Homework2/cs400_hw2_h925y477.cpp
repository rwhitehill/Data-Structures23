// Richard Whitehill
// Data Structures - CS 400
// Homework 2

// include functionality from other cpp files
#include <iostream>
#include <vector>
#include <numeric>

// helper function to print vector elements
template <class T>
void printVector(std::vector<T>& vec) {
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// function which generates the vector containing the rows of 
// pascal's triangle
std::vector<std::vector<int>> pascalTriangle(int rows) {
    std::vector<std::vector<int>> triangle;
    // number of rows must be at least one and cannot be more 
    // than 15 --> otherwise empty triangle is returned
    if (rows < 1 || rows > 16) {
        return triangle;
    }
    
    // initialize first row of triangle
    triangle.push_back({1});
    // loop through and calculate the next rows from the 
    // previous row entries
    for (auto i = 0; i < rows-1; i++) {
        std::vector<int> prev = triangle.back();
        std::vector<int> temp {1};
        for (auto j = 0; j < i; j++) {
            temp.push_back(prev[j] + prev[j+1]);
        }
        temp.push_back(1);
        triangle.push_back(temp);
    }
    return triangle;
}

// print pascal's triangle by looping through the rows and printing
// the vectors -- no implementation for "pretty print"
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    int j = triangle.size()-1;
    for (auto i : triangle) {
        printVector(i);
    }
}

// vector to compare pascal's triangle row sums to another vector
// and return true if they match and false otherwise
// NOTE: if the number of rows in the triangle is not equal to 
//       the number of entries in allegedSummations then an empty
//       vector is returned
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle, const std::vector<int>& allegedSummations) {
    std::vector<bool> temp;
    if (triangle.size() != allegedSummations.size()) {
        return temp;
    }

    for (auto i = 0; i < allegedSummations.size(); i++) {
        auto real_sum = std::accumulate(triangle[i].begin(),triangle[i].end(),0);
        temp.push_back(real_sum == allegedSummations[i]);
    }
    return temp;
}


int main() 
{
    // part 1: generate and print Pascal Triangle
    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);

    std::cout << std::endl;

    // part 2: check alleged summations
    std::vector<int> allegedSum {1,2,5,8,17,32,65,128,256,511};
    auto sumCheck = compare(pascalTriangle(allegedSum.size()),allegedSum);
    printVector(sumCheck);

    return 0;
}
