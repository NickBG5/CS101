#include <iostream>

using namespace std;

/* Program name: M06AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 4/16/2026
* Purpose: Program to determine the type of triangle based on the lengths of its sides.
* The program defines an enumeration type for triangle types and a function to determine the type of triangle
* based on the lengths of its sides. The main function prompts the user to enter the lengths of the sides and displays the type of triangle.
*/

// Define the enumeration type for triangle types
enum triangleType {scalene, isosceles, equilateral, noTriangle};

// Function to determine the type of triangle based on the lengths of its sides
triangleType triangleShape(double side1, double side2, double side3) {
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return noTriangle;
    } else if (side1 == side2 && side2 == side3) {
        return equilateral;
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {
        return isosceles;
    } else {
        return scalene;
    }
}

int main() {
    double side1, side2, side3;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> side1 >> side2 >> side3;

    triangleType type = triangleShape(side1, side2, side3);

    switch (type) {
        case scalene:
            cout << "The triangle is scalene." << endl;
            break;
        case isosceles:
            cout << "The triangle is isosceles." << endl;
            break;
        case equilateral:
            cout << "The triangle is equilateral." << endl;
            break;
        case noTriangle:
            cout << "The lengths do not form a triangle." << endl;
            break;
    }

    return 0;
}