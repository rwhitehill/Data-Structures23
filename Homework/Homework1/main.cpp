// Richard Whitehill        //
// Data Structures - CS 400 //
// Homework 1               //
//--------------------------//
//--------------------------//

// include input/output capabilities and math functionality
#include <iostream>
#include <cmath>

// function that checks if an input number is prime
bool is_prime(int num) {
    // by definition prime numbers are greater than one
    if (num <= 1) {
        return false;
    }
    // loop through possible factors of number and check divisibility
    for (auto i=2; i < sqrt(num)+1; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true;
}

// general prime generator quadratic form
int general_quadratic(int n, int a, int b) {
    return (pow(n,2) + a*n + b);
}

int main() {

    // Part 1: print the 40 primes generated by formula 1
    for (auto i = 0; i <= 39; i++) {
        std::cout << general_quadratic(i,1,41) << "  ";
    }
    std::cout << std::endl << std::endl;

    // Part 2: print the 80 primes generated by formula 2
    for (auto i = 0; i <= 79; i++) {
        std::cout << general_quadratic(i,-79,1601) << "  ";
    }
    std::cout << std::endl << std::endl;

    // Part 3: find the pair (a,b) such that the general quadratic
    // finds the most consecutive primes
    
    // initialize variables for loop
    int a; 
    int b;
    int most_consec_num_primes = 0;
    int temp_consec_num_primes;
    int n;

    // loop through possible values of a and b
    for (auto i=-999; i<=999; i++) {
        for (auto j=-1000; j <= 1000; j++) {
            n = 0;
            temp_consec_num_primes = 0;
           
            // check how many consecutive primes the quadratic generates
            while (is_prime(general_quadratic(n,i,j))) {
                temp_consec_num_primes++;
                n++;
            }
            
            // if more consecutive primes than previously found
            // store a and b as well as how many primes were generated
            if (temp_consec_num_primes > most_consec_num_primes) {
                most_consec_num_primes = temp_consec_num_primes;
                a = i;
                b = j;
            }
        }
    }
    // print out which pair (a,b) finds the most primes and 
    // how many were found
    std::cout << "(a,b) = " << "(" << a << "," << b << ")" << std::endl;
    std::cout << most_consec_num_primes << " consecutive primes generated" << std::endl;

    return 0;
}




