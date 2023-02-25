#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <fstream>

template <class T>
void print_list(std::list<T> lst) {
    for (auto it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class T>
void print_list_num(std::list<T> lst) {
    for (auto it = lst.rbegin(); it != lst.rend(); it++) {
        std::cout << *it << "";
    }
    std::cout << std::endl;

}

std::list<int> add_lists(std::list<int> list1, std::list<int> list2) {
    std::list<int> res;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
   
    int tens = 0;
    while (it1 != list1.end() || it2 != list2.end()) {
        int num1 = 0;
        int num2 = 0;
        if (it1 != list1.end()) {
            num1 = *it1;
            it1++;
        }
        if (it2 != list2.end()) {
            num2 = *it2;
            it2++;
        }
        int sum = num1 + num2 + tens;
        res.push_back(sum % 10);

        tens = (sum / 10)*(sum >= 10);
    }
    if (tens != 0) {
        res.push_back(tens);
    }

    return res;
}

int main() {
  
    std::fstream file;
    file.open("nums.txt");

    std::string line;
    std::list<int> sum; 
    sum.push_back(0);

    while (file >> line) {
        std::list<int> curr;
        for (auto i = 1; i <= line.length(); i++) {
            curr.push_back( (int) line[line.length()-i] - '0');
        }
        sum = add_lists(sum,curr);
    }

    file.close();

    print_list_num(sum);

    return 0;
}
