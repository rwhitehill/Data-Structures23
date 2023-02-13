// Richard Whitehill
// Data Structures - CS 400
// Homework 2

#include <iostream>
#include <vector>
#include <numeric>

template <class T>
void printVector(std::vector<T>& vec) {
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> pascalTriangle(int rows) {
    std::vector<std::vector<int>> triangle;
    if (rows < 1 || rows > 16) {
        return triangle;
    }

    triangle.push_back({1});
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

void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    for (auto i : triangle) {
        printVector(i);
    }
}

std::vector<bool> compare(const std::vector<std::vector<int>>& triangle, const std::vector<int>& allegedSummations) {
    std::vector<bool> temp;
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
    triangle = (pascalTriangle(allegedSum.size()));
    // auto sumCheck = compare(pascalTriangle(allegedSum.size()),allegedSum);
    auto sumCheck = compare(triangle,allegedSum);
    printVector(sumCheck);

    return 0;
}
