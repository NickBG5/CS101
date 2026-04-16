/* Program name: M02AssignCode02.cpp
* Author: Nicholas Garcia
* Date last updated: 3/24/2026
* Purpose:  Take 5 events as inputs and out them into a new file called events.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    string event;
    string eventDate;
    string reminderDate;

    ofstream MyFile("events.txt");

    for (int i = 0; i < 5; i++) {
        cout << "Enter event " << (i + 1) << ": ";
        getline(cin, event);
        cout << "Enter date for event " << (i + 1) << " (mm-dd-yyyy): ";
        getline(cin, eventDate);

        // Parse date
        tm tm = {};
        istringstream iss(eventDate);
        iss >> get_time(&tm, "%m-%d-%Y");
        if (iss.fail()) {
            cout << "Invalid date format. Skipping event." << endl;
            continue;
        }

        // Subtract 1 day
        tm.tm_mday -= 1;
        mktime(&tm); // Normalize

        // Format reminder date
        ostringstream oss;
        oss << put_time(&tm, "%m-%d-%Y");
        reminderDate = oss.str();

        MyFile << "|--------------------------------------------------|" << endl;
        MyFile << "| Event Name         | Event Date | Reminder Date  |" << endl;
        MyFile << "|--------------------------------------------------|" << endl;
        MyFile << "| " << left << setw(19) << event << "| " << setw(11) << eventDate << "| " << setw(14) << reminderDate << " |" << endl;
        MyFile << "|--------------------------------------------------|" << endl;
    }

    MyFile.close();
    char inptchr;
    cout << "Press any key to end the program...";
    cin >> inptchr;
    return 0;
}