// Richard Whitehill
// CS 400 
// Lab 1
// Objective: This program is prepared to find the 10001st prime number

#include <iostream> // import input/output functionality
#include <cmath> // import math functionality (sqrt for this program)

// Function to determine if a number (given as function argument) is a prime number
bool isPrime(int number) {
    // by definition primes have to be larger than 1
    if (number < 2) {
        return false;
    }
    // hard-coded case for 2 since method below gives that 2 is not a prime number
    else if (number == 2) {
        return true;
    }
    // iterate through possible factors of a number and test if loop index is a divisor 
    // of the number in question
    for (int i = 2; i <= sqrt(number) + 1; i++)
    {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find the 10001st prime number
int the10001PrimeNumber() {
    int current_prime = 2; // keeps track of current prime number that is stored
    int which_prime = 1; // keeps track of what number in the sequence our current prime is
    int i = 1; // stepping index for the loop below
               
    // loop that finds consecutive prime numbers until the 10001st prime is found 
    while (which_prime != 10001) {
        // ask if next number in sequence is prime 
        if (isPrime(current_prime + i)) {
            which_prime += 1; // if yes, increment prime sequence location
            current_prime = current_prime + i; // update current prime
            i = 1; // reset step index
        }
        else {
            i += 1; // if no, increment step index
        }
    }
    return current_prime;
}

int main()
{

    // Question 1: test isPrime() function by returning whether numbers 1-19 (inclusive)
    // are prime or not
    for (int i = 1; i <= 19; i++) {
        if (isPrime(i)) {
            std::cout << i << " is a prime number." << std::endl;
        }
        else {
            std::cout << i << " is NOT a prime number." << std::endl;
        }
    }

    std::cout << std::endl;

    // Question 2: Find the 10001st prime number (answer: 104743)
    std::cout << "The 10001st prime number: " << the10001PrimeNumber() << std::endl;

    return 0;
}

