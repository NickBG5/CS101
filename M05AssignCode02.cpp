//The cost to become a member of a fitness center is as follows: (a) the senior citizens discount is 30%; (b) if the membership is bought and paid for 12 or more months, the discount is 15%; and (c) if more than five personal training sessions are bought and paid for, the discount on each session is 20%. Write a menu-driven program that determines the cost of a new membership. Your program must contain a function that displays the general information about the fitness center and its charges, a function to get all of the necessary information to determine the membership cost, and a function to determine the membership cost. Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

#include <iostream>
#include <iomanip>

using namespace std;
/* Program name: M05AssignCode02.cpp
* Author: Nicholas Garcia
* Date last updated: 4/14/2026
* Purpose: Write a program that determines the cost of a new membership for a fitness center.
*/

void displayInfo() {
    cout << "Welcome to the Fitness Center!" << endl;
    cout << "Membership costs:" << endl;
    cout << "1. Senior citizens discount: 30%" << endl;
    cout << "2. Membership bought for 12 or more months: 15% discount" << endl;
    cout << "3. More than five personal training sessions: 20% discount on each session" << endl;
}

void getMembershipInfo(int &months, int &sessions, bool &isSenior) {
    cout << "Enter the number of months for membership: ";
    cin >> months;
    cout << "Enter the number of personal training sessions: ";
    cin >> sessions;
    cout << "Are you a senior citizen? (1 for yes, 0 for no): ";
    cin >> isSenior;
}

double calculateCost(int months, int sessions, bool isSenior) {
    double baseCost = 100.0; // Base cost for membership
    double totalCost = baseCost;

    if (isSenior) {
        totalCost *= 0.7; // Apply senior discount
    }
    if (months >= 12) {
        totalCost *= 0.85; // Apply long-term membership discount
    }
    if (sessions > 5) {
        totalCost += (sessions - 5) * 20 * 0.8; // Apply personal training session discount
    } else {
        totalCost += sessions * 20; // No discount for sessions
    }

    return totalCost;
}

int main() {
    displayInfo();

    int months, sessions;
    bool isSenior;
    getMembershipInfo(months, sessions, isSenior);

    double finalCost = calculateCost(months, sessions, isSenior);
    cout << fixed << setprecision(2);
    cout << "The total cost of your membership is: $" << finalCost << endl;

    return 0;
}