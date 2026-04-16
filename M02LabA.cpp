#include <iostream>
#include <iomanip>

using namespace std;

/* Program name: M02LabA.cpp
* Author: Nicholas Garcia
* Date last updated: 3/24/2026
* Purpose: Calculate the volume of an object given its mass and density
*/
int main()
{
    double massInGrams;
    double densityInGramsPerCubicCentimeter;

    cout << "Enter mass in grams: ";
    cin >> massInGrams;
    cout << "Enter density in grams per cubic centimeter: ";
    cin >> densityInGramsPerCubicCentimeter;

    double volumeInCubicCentimeters = massInGrams / densityInGramsPerCubicCentimeter;

    cout << fixed << setprecision(2);
    cout << "Volume in cubic centimeters: " << volumeInCubicCentimeters << endl;
    char inptchr;
    cout << "Press any key to end the program...";
    cin >> inptchr;
    return 0;
}