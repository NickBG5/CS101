#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;    

/* Program name: M02AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 3/23/2026
* Purpose:  Read a text file and display contents in a table
*/
int main() {
string myText;

ifstream MyReadFile("gradebook.txt");

cout << "+----------------+-------------------------------+-----------+-----------+" << endl;
cout << "| Student Num    | Student Name                  | Percent   | Grade     |" << endl;
cout << "+----------------+-------------------------------+-----------+-----------+" << endl;

while (getline (MyReadFile, myText)) {
    stringstream studentInfo(myText);
    string id, first, last, letter;
    double grade;
    
    studentInfo >> id >> first >> last >> grade >> letter;

    double gradePercent = grade * 100;
    string studentName = first + " " + last;
    
    cout << "| " << left << setw(15) << id << "| " << setw(30) << studentName << "| " << setw(10) << (stringstream() << fixed << setprecision(3) << gradePercent << "%").str() << "| " << setw(10) << letter << "|" << endl;
}
cout << "+----------------+-------------------------------+-----------+-----------+" << endl;

MyReadFile.close();
}