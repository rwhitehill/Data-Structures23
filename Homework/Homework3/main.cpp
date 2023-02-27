// import functionality from other files
#include <iostream>
#include <list>
#include <fstream>

// print list from head to tail using iterators
template <class T>
void print_list(std::list<T> lst) {
    for (auto it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// print list from tail to head using reverse iterators
template <class T>
void print_list_num(std::list<T> lst) {
    for (auto it = lst.rbegin(); it != lst.rend(); it++) {
        std::cout << *it << "";
    }
    std::cout << std::endl;

}

// function to add two lists together
std::list<int> add_lists(std::list<int> list1, std::list<int> list2) {
    // initialize result list and iterators for both lists
    std::list<int> res;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
  
    // loop to add numbers in list
    // tens holds the carry-over for place-value addition
    int tens = 0;
    while (it1 != list1.end() || it2 != list2.end()) {
        int num1 = 0;
        int num2 = 0;
        // get digit from first list and increment iterator if not end
        if (it1 != list1.end()) {
            num1 = *it1;
            it1++;
        }
        // get digit from second list and increment iterator if not end
        if (it2 != list2.end()) {
            num2 = *it2;
            it2++;
        }
        // get place-value for current digit by adding carry-over and
        // digits from lists
        int sum = num1 + num2 + tens;
        res.push_back(sum % 10);

        tens = (sum / 10)*(sum >= 10);
    }
    // for largest digit if carry-over from last operation add to list
    if (tens != 0) {
        res.push_back(tens);
    }

    return res;
}

int main() {
  
    // initialize file object and open file with numbers to add
    std::fstream file;
    file.open("nums.txt");

   
    // initialize line variable to read into
    // and sum as 0
    std::string line;
    std::list<int> sum; 
    sum.push_back(0);

    // read numbers from file (into curr), add to sum and store as new sum
    while (std::getline(file,line)) {
        std::list<int> curr;
        for (auto i = 1; i <= line.length(); i++) {
            curr.push_back( (int) line[line.length()-i] - '0');
        }
        sum = add_lists(sum,curr);
    }
    
    // close file
    file.close();

    // print out resultant sum
    print_list_num(sum);

    return 0;
}
