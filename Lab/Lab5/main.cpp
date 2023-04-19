// Richard Whitehill
// Data Structures (CS 400L)
// Lab 5
// 04/10/23

// import relevant functionality
#include <iostream>
#include <string>

// recursive function to generate permutations using fixed right
// string and left string which is looped over
void _permutation_(std::string left, std::string right) {
    // if no string to loop --> print permutation and return
    if (left.length() == 0) {
        std::cout << right << std::endl;
        return;
    }
    
    // implements backtracking
    // loop over left and add letter to right string and recursively 
    // call _permutation over new left and right strings
    for (auto i = 0; i < left.length(); ++i) {
        auto lockedLetter = left[i];
        std::string newLeft = left.substr(0,i) + left.substr(i+1);
        right.push_back(lockedLetter);
        _permutation_(newLeft,right);
        right.pop_back();
    }
}

// function that user calls to generate permutations
// initializes setup using _permutation_ function with empty fixed string
void permutation(std::string s) {
    return _permutation_(s,"");
}

int main() 
{
    // test case: generates 4! = 24 permuations of string
    std::string s = "abcd";
    permutation(s);
    
    return 0;
}
