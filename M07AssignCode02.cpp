/* Program name: M07AssignCode02.cpp
* Author: Nicholas Garcia
* Date last updated: 4/30/2026
* Purpose: Write a program that reads student names folloed by their test scores.  
* The program should output each student's name, their test score, and the relevant (computed) grade.  
* It should also find the highest test score and display it along with the name of student(s) receiving it
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    double testScore;
    char grade;
};

//Function to read student names and test scores from a file, compute their grades, and find the highest score
void processStudentScores(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    Student students[20];
    int studentCount = 0;
    string firstName, lastName;
    double score;
    double highestScore = -1.0;

    while (inFile >> firstName >> lastName >> score) {
        Student student;
        student.firstName = firstName;
        student.lastName = lastName;
        student.testScore = score;

        // Compute grade based on test score
        if (score >= 90) {
            student.grade = 'A';
        } else if (score >= 80) {
            student.grade = 'B';
        } else if (score >= 70) {
            student.grade = 'C';
        } else if (score >= 60) {
            student.grade = 'D';
        } else {
            student.grade = 'F';
        }

        students[studentCount++] = student;

        // Update highest score
        if (score > highestScore) {
            highestScore = score;
        }
    }

    inFile.close();

    // Output each student's name, test score, and grade
    cout << "Student Scores and Grades:" << endl;
    for (int i = 0; i < studentCount; i++) {
        const Student& student = students[i];
        cout << "Name: " << student.firstName << " " << student.lastName
             << ", Score: " << fixed << setprecision(2) << student.testScore 
             << ", Grade: " << student.grade << endl;
    }

    // Output the highest score and the names of students who received it
    cout << "\nHighest Score: " << fixed << setprecision(2) << highestScore << endl;
    cout << "Student(s) with the highest score:" << endl;
    for (int i = 0; i < studentCount; i++) {
        const Student& student = students[i];
        if (student.testScore == highestScore) {
            cout << student.firstName << " " << student.lastName <<  " " << student.testScore << endl;
        }
    }
}

int main() {
    string filename = "scores.txt";
    processStudentScores(filename);
    return 0;
}