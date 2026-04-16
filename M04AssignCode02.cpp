#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Program name: M04AssignCode02.cpp
* Author: Nicholas Garcia
* Date last updated: 4/7/2026
* Purpose: Convert binary number to decimal(Unlimited size of inputs)
* User will input 1 digit at at time and if they enter -1 the program will stop taking inputs
*/

int main()
{
    string binaryString;
    int i = 1;
    cout << "Welcome to binary number converter 2.0" << endl;
    cout << "You will enter a binary number 1 digit at a time starting at the right and the program will convert the number to decimal." << endl;
    
    while (true){
        cout << "Enter the " << i << " binary digit (Enter -1 to complete the conversion): ";
        string input;
        cin >> input;

        if (input == "-1") {
            break;
        }
        else if (input == "0" || input == "1") {
            binaryString = input + binaryString; // Prepend the new digit to the existing string
            i++;
        }
        else{
            cout << "Invalid input. Please enter 0, 1, or -1." << endl;
        }
    }
    // Using unsigned long long to handle larger decimal values, unsigned means it will not store negative values and long long means it can store larger values than int
    unsigned long long decimalValue = 0; 
    int power = 0;

    for (int i = binaryString.length() - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            // Calculate the decimal value by adding the value of the current bit (2^power) to the total decimal value
            decimalValue += pow(2, power);
        }
        power++;
    }

    cout << "Decimal value: " << decimalValue << endl;

    return 0;

}