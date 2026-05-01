#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>


using namespace std;

/* Program name: M07LabA.cpp
* Author: Nicholas Garcia
* Date last updated: 4/28/2026
* Purpose: Program to manage restaurant operations.
* Take no more than 50 reservations.
* The largest party the restaurant can handle for a reservation is 10 people.
* There will be 1 order per reservation, so there are also, at most, 50 orders
*/

struct Reservation {
    string customerName;
    int partySize;
    string reservationTime;
    bool isCheckedIn;
};

//Structed with the layout of the tableMenu.txt file, which has the format: tableID capacity numInParty originalReservationNum inUse ordered
struct Table {
    int tableNumber;
    int capacity;
    bool isOccupied;
};

//Structured with the layout of the menu.txt file, which has the format: itemName price
struct MenuItem {
    string itemName;
    double price;
};

//Structured to hold order information, including customer name, items ordered, total price, and status of the order (delivered and paid)
struct Order {
    string customerName;
    int ordTableNum;
    vector<string> itemsOrdered;
    double totalPrice;
    bool orderDelivered;
    bool orderPaid;
};

class Restaurant {
private:
    vector<Reservation> reservations;
    vector<Table> tables;
    vector<MenuItem> menu;
    vector<Order> orders;
public:
//Function to create the restaurant and load the table information from the tableMenu.txt file
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
        cout << "Restaurant created and tables loaded successfully!" << endl;
    }

//Function to load the menu items from the menu.txt file
    void loadMenu() {
        string itemName;
        double price;
        ifstream menuFile("menu.txt");
        if (!menuFile) {
            cerr << "Error opening menu file!" << endl;
            return;
        }
        string line;
        while (getline(menuFile, line)) {
            stringstream ss(line);
            ss >> itemName >> price;
            MenuItem menuItem;
            menuItem.itemName = itemName;
            menuItem.price = price;
            menu.push_back(menuItem);
        }
        cout << "Menu loaded successfully!" << endl;
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

 //Function to view all reservations
    void viewReservations() {
        if (reservations.empty()) {
            cout << "No reservations found." << endl;
            return;
        }
        cout << "Current Reservations:" << endl;
        for (const auto& res : reservations) {
            cout << "Name: " << res.customerName 
                 << ", Time: " << res.reservationTime 
                 << ", Party Size: " << res.partySize 
                 << ", Checked In: " << (res.isCheckedIn ? "Yes" : "No") 
                 << endl;
        }
    }
//Function to view all tables and their status
    void viewTables() {
        cout << "Table Status:" << endl;
        for (const auto& table : tables) {
            cout << "Table " << table.tableNumber 
                 << ": Capacity " << table.capacity 
                 << ", Occupied: " << (table.isOccupied ? "Yes" : "No") 
                 << endl;
        }
    }

//Function to view all current orders and their status
    void viewOrders() {
        if (orders.empty()) {
            cout << "No orders found." << endl;
            return;
        }
        cout << "Current Orders:" << endl;
        for (const auto& order : orders) {
            cout << "Customer Name: " << order.customerName 
                 << ", Table Number: " << order.ordTableNum
                 << ", Items Ordered: ";
            for (const auto& item : order.itemsOrdered) {
                cout << item << " ";
            }
            cout << ", Total Price: $" << fixed << setprecision(2) << order.totalPrice 
                 << ", Delivered: " << (order.orderDelivered ? "Yes" : "No") 
                 << ", Paid: " << (order.orderPaid ? "Yes" : "No") 
                 << endl;
        }
    }


//Function to check in a reservation, remove them from the reservation list and seat them to a table
    void checkIn() {
        string name;
        int partySize = 0;
        int reservationIndex = -1;

        cout << "Enter customer name for check-in: ";
        getline(cin, name);

        for (int i = 0; i < reservations.size(); ++i) {
            if (reservations[i].customerName == name) {
                reservations[i].isCheckedIn = true;
                partySize = reservations[i].partySize; // Store party size before erasing
                reservationIndex = i;
                cout << "Check-in successful!" << endl;
                reservations[reservationIndex].isCheckedIn = true; 
                //reservations.erase(reservations.begin() + i); commenting this out because I want to keep the reservation and remove it later after paying
                break;
            } 
        }

        if (reservationIndex == -1) {
            cout << "Reservation not found. Please try again." << endl;
            return;
        }

        cout << "Please assign to a table." << endl;

        for(auto &table : tables) {
            if (table.isOccupied == false) {
                cout << table.tableNumber << " : " << table.capacity << " seats" << endl;
            }
        }
            cout << "Enter table number to seat the party: ";
            int tableNum;
            cin >> tableNum;

        for(auto &table : tables) {
            if (tableNum == table.tableNumber) {
                if(partySize <= table.capacity) { 
                    table.isOccupied = true;
                    cout << "Party seated at table " << table.tableNumber << "." << endl;
                    return;
                } else {
                cout << "Party size exceeds table capacity. Please try again." << endl;
                }
            }
        }
        cout << "Invalid table number. Please try again." << endl;
    }

//Function to see the menu
    void seeMenu() {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << item.itemName << " - $" << fixed << setprecision(2) << item.price << endl;
        }
    }

//Function to take an order
    void takeOrder() {
        int ordTableNum;

        cout << "Enter your table number: ";
        cin >> ordTableNum;
        cin.ignore(); // Clear the input buffer
        cout << "Can I take your order?" << endl;

        seeMenu(); // Show the menu to the customer before taking the order

        string orderItem;
        vector<string> itemsOrdered;
        double totalPrice = 0.0;

        while (true) {
            cout << "Enter item name (or 'done' to finish): ";
            getline(cin, orderItem);
            if (orderItem == "done") {
                break;
            }
            bool itemFound = false;
            for (const auto& menuItem : menu) {
                if (menuItem.itemName == orderItem) {
                    itemsOrdered.push_back(orderItem);
                    totalPrice += menuItem.price;
                    itemFound = true;
                    break;
                }
            }
            if (!itemFound) {
                cout << "Item not found on the menu. Please try again." << endl;
            }
        }

    }
//Function to serve an order and update the order status as devlivered
    void serveOrder() {

        int ordTableNum;
        cout << "Enter table number to serve order: ";
        cin >> ordTableNum;
        for(auto &order : orders) {
            if(ordTableNum < 1 || ordTableNum > 50) {
                cout << "Invalid table number. Please try again." << endl;
                return;
            } else if (order.ordTableNum == ordTableNum) {
                order.orderDelivered = true;
                cout << "Order for table " << ordTableNum << " has been served." << endl;
                return;
            }
        }
        cout << "Order for table " << ordTableNum << " not found." << endl;
    }
};

int main() {
    Restaurant messiJoes;
    int choice;

    messiJoes.createRestaurant(); // Initialize the restaurant and load tables from file
    messiJoes.loadMenu(); // Load menu items from file
     
    do {
        cout << "Welcome to MessiJoes!" << endl;
        cout << "1. Make a reservation" << endl;
        cout << "2. Check-in and be seated" << endl;
        cout << "3. View reservations" << endl;
        cout << "4. View tables" << endl;
        cout << "5. View orders" << endl;
        cout << "6. Take an order" << endl;
        cout << "7. See menu" << endl;
        cout << "8. Serve order" << endl;
        cout << "9. Exit" << endl;
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
            case 3:
                messiJoes.viewReservations();
                break;
            case 4:
                messiJoes.viewTables();
                break;
            case 5:
                messiJoes.viewOrders();
                break;
            case 6:
                messiJoes.takeOrder();
                break;
            case 7:
                messiJoes.seeMenu();
                break;
            case 8:
                messiJoes.serveOrder();
                break;
            case 9:
                cout << "Thank you for visiting MessiJoes!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);
    return 0;
}