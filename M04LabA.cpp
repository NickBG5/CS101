#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* Program name: M04LabA.cpp
* Author: Nicholas Garcia
* Date last updated: 4/7/2026
* Purpose: Write a program that prompts the user to enter two integers. 
* The program outputs how many numbers are multiples of 3 and how many numbers are multiples of 5 between the two integers (inclusive)
*/

int main() {
    int num1, num2;

    cout << " Enter two integers: ";

    cin >> num1 >> num2;

    int countMultiplesOf3 = 0;
    int countMultiplesOf5 = 0;

    for (int i = num1; i <= num2; i++) {
        if (i % 3 == 0) {
            cout << i << " is a multiple of 3." << endl;
            countMultiplesOf3++;
        }
        if (i % 5 == 0) {
            cout << i << " is a multiple of 5." << endl;
            countMultiplesOf5++;
        }
    }
    cout << "Multiples of 3: " << countMultiplesOf3 << endl;
    cout << "Multiples of 5: " << countMultiplesOf5 << endl;

}
    
