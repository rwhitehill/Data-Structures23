#include <iostream>
#include <string>

void permutation(std::string left, std::string right) {
    if (left.length() == 0) {
        std::cout << right << std::endl;
        return;
    }

    for (auto i = 0; i < left.length(); ++i) {
        auto lockedLetter = left[i];
        std::string newLeft = left.substr(0,i) + left.substr(i+1);
        right.push_back(lockedLetter);
        permutation(newLeft,right);
        right.pop_back();
    }
}

int main() 
{
    //std::string s = "abcdefg";

    //std::cout << s.substr(0,3) << std::endl; // expect result of "abc"
    //std::cout << s.substr(3) << std::endl; // expect result of "defg"
    //std::cout << s.substr(0,1) << std::endl; // expect "a"
    
    std::string s = "abcd";
    permutation(s,"");
    
    return 0;
}
