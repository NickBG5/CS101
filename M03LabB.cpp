/* Program name: M03LabB.cpp
*  Author: Nicholas Garcia
*  Date last updated: 4/02/2026
* Purpose: Given an input of three side lengths, determine if they can form a right triangle.
A*A + B*B = C*C where C is the longest side (hypotenuse)
WIP1 verify exact equalities for pythagorean triples e: 3,4,5, and 5, 12, 13.
other rigle trianlges have irrational sides Ex: 1,1,sqrt(2) and 1,2,sqrt(5)

*/

#include <iostream> //cin cout
#include <cmath> //sqrt() square root
#include <iomanip> //setprecision() formatting
using namespace std;

int main() {
    double side1, side2, side3;
    int intSide1, intSide2, intSide3;
    cout << "Enter three side lengths: ";
    cin >> side1 >> side2 >> side3;

    // Convert the side lengths to integers for comparison
    intSide1 = static_cast<int>(side1);
    intSide2 = static_cast<int>(side2);
    intSide3 = static_cast<int>(side3);

    if(intSide1 * intSide1 + intSide2 * intSide2 == intSide3 * intSide3 ||
       intSide1 * intSide1 + intSide3 * intSide3 == intSide2 * intSide2 ||
       intSide2 * intSide2 + intSide3 * intSide3 == intSide1 * intSide1) {
        cout << "The sides " << side1 << ", " << side2 << ", and " << side3 << " can form a right triangle." << endl;
    } else {
        cout << "The sides " << side1 << ", " << side2 << ", and " << side3 << " cannot form a right triangle." << endl;
    }
    double tolerance = 0.0001; // Define a small tolerance for floating-point comparison
    double hypoteneuse, leg1, leg2;

    if(side1 >= side2 && side1 >= side3) {
        hypoteneuse = side1;
        leg1 = side2;
        leg2 = side3;
    } else if (side2 >= side1 && side2 >= side3) {
        hypoteneuse = side2;
        leg1 = side1;
        leg2 = side3;
    } else {
        hypoteneuse = side3;
        leg1 = side1;
        leg2 = side2;
    }

    if(abs((leg1 * leg1 + leg2 * leg2) - (hypoteneuse * hypoteneuse)) < tolerance) {
        cout << "The sides can form a right triangle (within tolerance)." << endl;
    } else {
        cout << "The sides cannot form a right triangle (even within tolerance)." << endl;
    }

return 0;
}