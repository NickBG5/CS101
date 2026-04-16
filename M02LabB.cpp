
#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip> 
 
using namespace std;

/* Program name: M02LabB.cpp
* Author: Nicholas Garcia
* Date last updated: 3/26/2026
* Purpose:  Read a employee text file, calculate the new salary with the increase, and output to a new file
*/
int main() {
string myText;
string first, last;
double currentSalary, increaseRate;

ifstream MyReadFile("Ch3_Ex5Data.txt");

while (getline (MyReadFile, myText)) {
    stringstream employeeInfo(myText);
    
    employeeInfo >> first >> last >> currentSalary >> increaseRate;

    double updatedSalary = currentSalary + (currentSalary * (increaseRate / 100));

    ofstream MyFile("Ch3_Ex5Output.txt", ios::app);

    MyFile << first << " " << last << " " << fixed << setprecision(2) << updatedSalary << endl;
    MyFile.close();
}
    MyReadFile.close(); 

    char inptchr;
    cout << "Press any key to end the program...";
    cin >> inptchr;
    return 0;
}