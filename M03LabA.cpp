#include <iostream>
using namespace std;

/* Program name: M03LabA.cpp
*  Author: Nicholas Garcia
*  Date last updated: 3/31/2026
* Purpose: Program will determin if an input number is positive, negative or zero
* WIP1 - Introduce while loop to allow multiple inputs on same run
          Recieve number from console and display it and whether it is positive, negative or zero
* WIP2 - Add error handling for non-number inputs. In the form of try/throw/catch blocks.
         Add a user defined function to handle the input validation. function getNumber() this will return a valid double value after checking for good input.
*/
double getNumber();

int main() {
    char another = 'y';
    double num;

    while (another == 'y') {
        num = getNumber();
        cout << "You entered: " << num << endl;

        if(num > 0) {
            cout << "The number is positive." << endl;
        } else if (num < 0) {
            cout << "The number is negative." << endl;
        } else {
            cout << "The number is zero." << endl;
        }

        cout << "Do you want to enter another number? (y/n): ";
        cin >> another;
    }
}

double getNumber() {
    double num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        if (!cin) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            return num;
        }
    }
}