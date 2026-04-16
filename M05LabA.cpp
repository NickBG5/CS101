#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/* Program name: M05LabA.cpp
* Author: Nicholas Garcia
* Date last updated: 4/14/2026
* Purpose: Program to manage restaurant operations.
* Take no more than 50 reservations.
* The largest party the restaurant can handle for a reservation is 10 people.
*/

struct Reservation {
    string customerName;
    int partySize;
    string reservationTime;
    bool isCheckedIn;
};

class Restaurant {
private:
    vector<Reservation> reservations;
public:
    void makeReservation() {
        if (reservations.size() >= 50) {
            cout << "Sorry, we cannot take more reservations at this time." << endl;
            return;
        }
        Reservation newReservation;
        cout << "Enter customer name: ";
        getline(cin, newReservation.customerName);
        cout << "Enter party size (max 10): ";
        cin >> newReservation.partySize;
        if (newReservation.partySize > 10) {
            cout << "Party size cannot exceed 10. Please try again." << endl;
            return;
        }
        cout << "Enter reservation time HH:MM AM/PM: ";
        cin >> newReservation.reservationTime;
        newReservation.isCheckedIn = false;
        reservations.push_back(newReservation);
        cout << "Reservation made successfully!" << endl;
    }
    void checkIn() {
        string name;
        cout << "Enter customer name for check-in: ";
        getline(cin, name);
        for (auto &reservation : reservations) {
            if (reservation.customerName == name) {
                reservation.isCheckedIn = true;
                cout << "Check-in successful!" << endl;
                return;
            }
        }
        cout << "Reservation not found." << endl;
    }

};

int main() {
    Restaurant messiJoes;
    int choice;
    do {
        cout << "Welcome to MessiJoes!" << endl;
        cout << "1. Make a reservation" << endl;
        cout << "2. Check-in" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        switch (choice) {
            case 1:
                messiJoes.makeReservation();
                break;
            case 2:
                messiJoes.checkIn();
                break;
            case 6:
                cout << "Thank you for visiting MessiJoes!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}