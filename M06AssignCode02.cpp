#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/* Program name: M06AssignCode02.cpp
 * Author: Nicholas Garcia
 * Date last updated: 4/16/2026
 * Purpose: Program to compute weekly pay for temporary workers and determine which employees have above average weekly pay.
 * The program reads employee data from a file, calculates weekly pay based on hours worked and
 * hourly pay rate, and outputs the pay details for each employee. It also identifies and displays the names of employees whose weekly pay is greater than or equal to the average weekly pay.
*/

const int NUM_EMPLOYEES = 10;
const int NUM_DATA_FIELDS = 3; // hourly pay, hours worked, gross pay

void readEmployeeData(string names[], double data[NUM_EMPLOYEES][NUM_DATA_FIELDS]) {
    ifstream inputFile("ch8_Ex17Data.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        inputFile >> names[i] >> data[i][1] >> data[i][0]; // Read name, hours worked, hourly pay
    }
    inputFile.close();
}

double calculateWeeklyPay(double hourlyPay, double hoursWorked) {
    if (hoursWorked > 40) {
        return (40 * hourlyPay) + ((hoursWorked - 40) * hourlyPay * 1.5);
    } else {
        return hoursWorked * hourlyPay;
    }
}

int main() {
    string employeeNames[NUM_EMPLOYEES];
    double employeeData[NUM_EMPLOYEES][NUM_DATA_FIELDS]; // [][0] = hourly pay, [][1] = hours worked, [][2] = gross pay
    double totalPay = 0.0;

    readEmployeeData(employeeNames, employeeData);

    cout << fixed << setprecision(2);
    cout << "Employee Pay Details:" << endl;
    cout << "Name\tHourly Pay\tHours Worked\tWeekly Pay" << endl;

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        double weeklyPay = calculateWeeklyPay(employeeData[i][0], employeeData[i][1]);
        employeeData[i][2] = weeklyPay; // Store gross pay
        totalPay += weeklyPay;
        cout << employeeNames[i] << "\t" << employeeData[i][0] << "\t\t" << employeeData[i][1] << "\t\t" << weeklyPay << endl;
    }

    double averagePay = totalPay / NUM_EMPLOYEES;
    cout << "\nAverage Weekly Pay: $" << averagePay << endl;

    cout << "\nEmployees with Weekly Pay Greater than or Equal to Average:" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        if (employeeData[i][2] >= averagePay) {
            cout << employeeNames[i] << " with Weekly Pay: $" << employeeData[i][2] << endl;
        }
    }

    return 0;
}