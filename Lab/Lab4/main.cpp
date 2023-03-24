#include <iostream>
#include <vector>
#include <list>

void print_listnum(const std::list<int>& list) {
    for(auto it = list.rbegin(); it != list.rend(); it++) {
        std::cout << *it;
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

std::list<int> multiply_lists(std::list<int> l1, std::list<int> l2) {
    std::list<int> res { 0 };
  
    int i = 0;
    int prod,ones,carry;
    for(auto it2 = l2.begin(); it2 != l2.end(); it2++) {
        std::list<int> temp;
        carry = 0;
        for(auto it1 = l1.begin(); it1 != l1.end(); it1++) {
            prod  = *it1 * *it2 + carry;
            ones  = prod % 10;
            carry = prod / 10;
            temp.push_back(ones);
        }
        if (carry != 0) {
            temp.push_back(carry);
        }
        for (int j = 1; j <= i; j++) {
            temp.push_front(0);
        }
        res = add_lists(res,temp);
        i ++;
    }

    return res;
}

std::list<int> convert_int_to_list(int n) {
    std::list<int> list;
    while (n != 0) {
        list.push_back(n % 10);
        n = n / 10;
    }
    return list;
}

void factorial(int n) {
    std::list<int> res {1};
    for(auto i = 2; i <= n; i++) {
        res = multiply_lists(res,convert_int_to_list(i));
    }
    print_listnum(res);
}

int main() {

    factorial(10);
    std::cout << std::endl;
    factorial(100);
    std::cout << std::endl;
    factorial(1000);
    std::cout << std::endl;

    return 0;
}



