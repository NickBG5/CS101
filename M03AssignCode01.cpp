#include <iostream>

/* Program name: M03AssignCode01.cpp
*  Author: Nicholas Garcia
*  Date last updated: 3/31/2026
* Purpose: Prompt the user for the amount of RAM their computer has in GB. Then display the list of tasks below that the user might do with the computer. Based on the task chosen, inform the user if the amount of RAM they have is sufficient
*/
using namespace std;

int main() {
    int ramGB;
    int taskChoice;

    cout << "Enter the amount of RAM in GB: ";
    cin >> ramGB;
    if(!cin >> ramGB || ramGB < 0) {
        cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
        return 1;
    } else {
    cout << "Choose the task you want to do on your computer from the following list:" << endl;
    cout << "1. Android Studio" << endl;
    cout << "2. Visual Studio Code" << endl;
    cout << "3. Gaming" << endl;
    cout << "4. Web Browsing with Chrome" << endl;
    cout << "5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)" << endl;
    cout << "6. Zoom" << endl;
    cout << "7. Email" << endl;
    cout << "8. Create and edit documents" << endl;
    cout << "9. Everything listed above" << endl;
    cin >> taskChoice;
    }

    if(!cin >> taskChoice || taskChoice < 1 || taskChoice > 9) {
        cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
        return 1;
    }

    switch (taskChoice) {
    case 1:
        if (ramGB >= 12) {
            cout << "You have sufficient RAM for Android Studio." << endl;
        } else {
            cout << "You do not have sufficient RAM for Android Studio." << endl;
        }
        break;
    case 2:
        if (ramGB >= 8) {
            cout << "You have sufficient RAM for Visual Studio Code." << endl;
        } else {
            cout << "You do not have sufficient RAM for Visual Studio Code." << endl;
        }
        break;
    case 3:
        if (ramGB >= 16) {
            cout << "You have sufficient RAM for Gaming." << endl;
        } else {
            cout << "You do not have sufficient RAM for Gaming." << endl;
        }
        break;
    case 4:
        if (ramGB >= 8) {
            cout << "You have sufficient RAM for Web Browsing with Chrome." << endl;
        } else {
            cout << "You do not have sufficient RAM for Web Browsing with Chrome." << endl;
        }
        break;
    case 5:
        if (ramGB >= 20) {
            cout << "You have sufficient RAM for Multiple Programming Tasks." << endl;
        } else {
            cout << "You do not have sufficient RAM for Multiple Programming Tasks." << endl;
        }
        break;
    case 6:
        if (ramGB >= 8) {
            cout << "You have sufficient RAM for Zoom." << endl;
        } else {
            cout << "You do not have sufficient RAM for Zoom." << endl;
        }
        break;
    case 7:
        if (ramGB >= 6) {
            cout << "You have sufficient RAM for Email." << endl;
        } else {
            cout << "You do not have sufficient RAM for Email." << endl;
        }
        break;
    case 8:
        if (ramGB >= 6) {
            cout << "You have sufficient RAM for Create and edit documents." << endl;
        } else {
            cout << "You do not have sufficient RAM for Create and edit documents." << endl;
        }
        break;
    case 9:
        if (ramGB >= 32) {
            cout << "You have sufficient RAM for Everything listed above." << endl;
        } else {
            cout << "You do not have sufficient RAM for Everything listed above." << endl;
        }
    
    default:
        break;
    }

}
