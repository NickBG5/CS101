#include <iostream>

using namespace std;

/* Program name: M04LabB.cpp
* Author: Nicholas Garcia
* Date last updated: 4/9/2026
* Purpose: Write a program that prompts the user to input a positive integer. 
* It should then output a message indicating whether the number is a prime number.
*/
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false; // num is divisible by a number other than 1 and itself
        }
    }
    return true; // num is a prime number
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}