#include <iostream>

using namespace std;
/* Program name: M01ALab.cpp
* Author: Nicholas Garcia
* Date last updated: 3/17/2026
* Purpose: Take 5 test scores and calculate the average
*/


int main()
{
    double firstTestScore, secondTestScore, thirdTestScore, fourthTestScore, fifthTestScore, averageTestScore;

    cout << "Enter the first test score: ";
    cin >> firstTestScore;
    cout << "Enter the second test score: ";
    cin >> secondTestScore;
    cout << "Enter the third test score: ";
    cin >> thirdTestScore;
    cout << "Enter the fourth test score: ";
    cin >> fourthTestScore;
    cout << "Enter the fifth test score: ";
    cin >> fifthTestScore;

    averageTestScore = (firstTestScore + secondTestScore + thirdTestScore + fourthTestScore + fifthTestScore) / 5;

    cout << "The average test score is: " << averageTestScore << endl;

    return 0;
}