#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>


using namespace std;

/* Program name: M05LabB.cpp
* Author: Nicholas Garcia
* Date last updated: 4/16/2026
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

struct Table {
    int tableNumber;
    int capacity;
    bool isOccupied;
};

class Restaurant {
private:
    vector<Reservation> reservations;
    vector<Table> tables;
public:
//Functio to create the restaurant and load the table information from the tableMenu.txt file
    void createRestaurant() {
        int tableID, tableCapacity, tableNumInParty, tableOriginalReservationNum;
        bool tableInUse, tableOrdered;
        // Read tableMenu.txt and initialize the tables based on the file contents
        ifstream tableMenuFile("tableMenu.txt");
        if (!tableMenuFile) {
            cerr << "Error opening table menu file!" << endl;
            return;
        }
        string line;
        while (getline(tableMenuFile, line)) {
            // Parse the line and initialize the table information
            stringstream ss(line);
            ss >> tableID >> tableCapacity >> tableNumInParty >> tableOriginalReservationNum >> tableInUse >> tableOrdered;
            Table table;
            table.tableNumber = tableID;
            table.capacity = tableCapacity;
            table.isOccupied = false;
            tables.push_back(table);
        }
    }

    //Function to make a reservation, checks for maximum reservations and party size, and confirms the reservation with the user.
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
        cout << "Please confirm your reservation: " << endl;
        cout << "Name: " << newReservation.customerName << endl;
        cout << "Reservation Time: " << newReservation.reservationTime << endl;
        cout << "Party Size: " << newReservation.partySize << endl;
        cout << "Confirm reservation? (Y/N): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y') {
            newReservation.isCheckedIn = false;
            reservations.push_back(newReservation);
            cout << "Reservation made successfully!" << endl;
        } else {
            cout << "Reservation cancelled." << endl;
        }
    }
//Function to check in a reservation, remove them from the reservation list and seat them to a table
    void checkIn() {
        string name;
        int partySize = 0;
        cout << "Enter customer name for check-in: ";
        getline(cin, name);
        for (int i = 0; i < reservations.size(); ++i) {
            if (reservations[i].customerName == name) {
                reservations[i].isCheckedIn = true;
                partySize = reservations[i].partySize; // Store party size before erasing
                cout << "Check-in successful!" << endl;
                reservations.erase(reservations.begin() + i); // Remove the reservation after check-in
                cout << "Please assign to a table." << endl;
            } else {
                cout << "Reservation not found." << endl;
            }
        }
        for(auto &table : tables) {
            if (table.isOccupied == false) {
                cout << table.tableNumber << ":" << table.capacity << " seats" << endl;
            }
        }
                cout << "Enter table number to seat the party: ";
                int tableNum;
                cin >> tableNum;
                cout << tableNum << " " << tables[tableNum].tableNumber << " " << partySize << " " << tables[tableNum].capacity << endl;
                if (tableNum == tables[tableNum].tableNumber - 1 && partySize <= tables[tableNum].capacity) { 
                    tables[tableNum].isOccupied = true;
                    cout << "Party seated at table " << tables[tableNum].tableNumber << "." << endl;
                    return;
                } else {
                    cout << "Invalid table number or party size exceeds table capacity. Please try again." << endl;
                }
            }

};

int main() {
    Restaurant messiJoes;
    int choice;
    messiJoes.createRestaurant(); // Initialize the restaurant and load tables from file
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