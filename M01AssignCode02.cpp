#include <iostream>

using namespace std;
/* Program name: M01AssignCode02.cpp
* Author: Nicholas Garcia
* Date last updated: 3/19/2026
* Purpose: Distribute jackpot among winners
*/


int main()
{
    int numberOfWinners;
    double jackpotAmount, amountForFirstWinner;
    cout << "Enter the jackpot amount: ";
    cin >> jackpotAmount;
    cout << "Enter the number of winners: ";
    cin >> numberOfWinners;

    double otherAmount = jackpotAmount / (numberOfWinners + 1);
    amountForFirstWinner = otherAmount * 2;


    cout << "The first winner gets: $" << amountForFirstWinner << endl;
    cout << "All the other winners get: $" << otherAmount << endl;

    return 0;
}