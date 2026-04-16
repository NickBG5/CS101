#include <iostream>

using namespace std;

/* Program name: M01AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 3/17/2026
* Purpose: Convert binary number to decimal
*/

int main()
{
    int digit1, digit2, digit3, digit4, digit5;
    int decimalValue;
    cout << "Enter the 1st binary digit: ";
    cin >> digit1;
    cout << "Enter the 2nd binary digit: ";
    cin >> digit2;
    cout << "Enter the 3rd binary digit: ";
    cin >> digit3;
    cout << "Enter the 4th binary digit: ";
    cin >> digit4;
    cout << "Enter the 5th binary digit: ";
    cin >> digit5;

    decimalValue = digit1 * 16 + digit2 * 8 + digit3 * 4 + digit4 * 2 + digit5 * 1;

    cout << "The binary number ";
    cout << digit1 << digit2 << digit3 << digit4 << digit5;
    cout << " converted to decimal is " << decimalValue << endl;

    return 0;
}

