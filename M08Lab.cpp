#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>


using namespace std;

/* Program name: M08Lab.cpp
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
    bool isCheckedIn = false;
    int tableNumber = 0;
};

//Structed with the layout of the tableMenu.txt file, which has the format: tableID capacity numInParty originalReservationNum inUse ordered
struct Table {
    int tableNumber;
    int capacity;
    bool isOccupied = false;
};

//Structured with the layout of the menu.txt file, which has the format: itemName price
struct MenuItem {
    int itemID;
    string itemName;
    double price;
};

//Structured to hold order information, including customer name, items ordered, total price, and status of the order (delivered and paid)
struct Order {
    string customerName;
    int ordTableNum;
    vector<string> itemsOrdered;
    double totalPrice = 0.0;
    bool orderDelivered = false;
    bool orderPaid = false;
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
            menuItem.itemID = menu.size() + 1; // Assign a unique ID based on the current size of the menu
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
                    reservations[reservationIndex].tableNumber = tableNum;
                    cout << "Party seated at table " << table.tableNumber << "." << endl;
                } else {
                    cout << "Party size exceeds table capacity. Please try again." << endl;
                }
                break;
            } 
        }
    }

//Function to see the menu
    void seeMenu() {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << item.itemID << ". " << item.itemName << " - $" << fixed << setprecision(2) << item.price << endl;
        }
    }

//Function to take an order
    void takeOrder() {
        int ordTableNum;
        Order newOrder;
        string orderItem;

        cout << "Enter your table number: ";
        cin >> ordTableNum;
        cin.ignore(); // Clear the input buffer

        string customerNameForOrder;
        bool reservationMatched = false;
        for (const auto& res : reservations) {
            if (res.isCheckedIn && res.tableNumber == ordTableNum) {
                customerNameForOrder = res.customerName;
                reservationMatched = true;
                break;
            }
        }
        if (!reservationMatched) {
            cout << "No checked-in reservation found for table " << ordTableNum << ". Please check in the customer first." << endl;
            return;
        }

        cout << "Can I take your order?" << endl;

        seeMenu(); // Show the menu to the customer before taking the order

        while (true) {
            cout << "Enter item number (or 'done' to finish): ";
            getline(cin, orderItem);

            if (orderItem == "done" || orderItem == "DONE" || orderItem == "Done") {
                orders.push_back(newOrder); // Add the new order to the orders vector
                cout << "Order taken successfully!" << endl;
                break;
            }

            if (orderItem.empty()) {
                cout << "Please enter a menu item number or 'done'." << endl;
                continue;
            }

            bool validNumber = true;
            for (char c : orderItem) {
                if (!isdigit(static_cast<unsigned char>(c))) {
                    validNumber = false;
                    break;
                }
            }

            if (!validNumber) {
                cout << "Invalid input. Please enter a menu item number or 'done'." << endl;
                continue;
            }

            int selectedID = stoi(orderItem);
            bool itemFound = false;
            for (const auto& menuItem : menu) {
                if (menuItem.itemID == selectedID) {
                    newOrder.customerName = customerNameForOrder;
                    newOrder.ordTableNum = ordTableNum;
                    newOrder.itemsOrdered.push_back(orderItem);
                    newOrder.totalPrice += menuItem.price;
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
            } else if (order.ordTableNum == ordTableNum) {
                // Update the order status as delivered
                order.orderDelivered = true;
                cout << "Order for table " << ordTableNum << " has been served." << endl;
            }
        }
    }

//Function to calculate the total for an order, including a 20% tip and 10% tax, and update the order status as paid
    void calculateBill() {
        int ordTableNum;
        double tipPercentage = 0.2, taxPercentage = 0.1, tax = 0.0, tip = 0.0, totalWithTipAndTax = 0.0;

        cout << "Enter table number to calculate total: ";
        cin >> ordTableNum;

        bool orderFound = false;
        for(auto &order : orders) {
            if (order.ordTableNum == ordTableNum) {
                orderFound = true;
                tip = order.totalPrice * tipPercentage;
                tax = order.totalPrice * taxPercentage;
                totalWithTipAndTax = order.totalPrice + tip + tax;
                
                cout << "Total price for table " << ordTableNum << " is $" << fixed << setprecision(2) << order.totalPrice << endl;
                cout << "Tip for table " << ordTableNum << " is $" << fixed << setprecision(2) << tip << endl;
                cout << "Tax for table " << ordTableNum << " is $" << fixed << setprecision(2) << tax << endl;
                cout << "Total with tip and tax for table " << ordTableNum << " is $" << fixed << setprecision(2) << totalWithTipAndTax << endl;

                cout << "Do you want to pay now? (Y/N): ";
                char payNow;
                cin >> payNow;

                if (payNow == 'Y' || payNow == 'y') {
                    // Update the order status as paid
                    order.orderPaid = true;
                    cout << "Order for table " << ordTableNum << " has been paid." << endl;
                } else {
                    cout << "Payment deferred for table " << ordTableNum << "." << endl;
                }
                break; // Only process the first matching order
            }
        }
        if (!orderFound) {
            cout << "No order found for table " << ordTableNum << "." << endl;
        }
    }

//Function to remove a reservation after payment is completed
    void removeReservation() {
        if (reservations.empty()) {
            cout << "No reservations to remove." << endl;
            return;
        }

        for (const auto& order : orders) {
            if (order.orderPaid == true) {
                for (auto it = reservations.begin(); it != reservations.end(); ) {
                    if (it->customerName == order.customerName) {
                        cout << "Reservation for " << order.customerName << " has been removed." << endl;
                        it = reservations.erase(it);
                    } else {
                        ++it;
                    }
                }
            for(auto &table : tables) {
                if (order.ordTableNum == table.tableNumber && order.orderPaid) {
                    table.isOccupied = false; // Free up the table when the reservation is removed
                    cout << "Table " << table.tableNumber << " is now available." << endl;
                    }
                }
            }
        }
    }

//Function to remove an order after payment is completed
    void removeOrder() {
        if (orders.empty()) {
            cout << "No orders to remove." << endl;
            return;
        }

        for (auto it = orders.begin(); it != orders.end(); ) {
            if (it->orderPaid) {
                cout << "Order for " << it->customerName << " has been removed." << endl;
                it = orders.erase(it);
            } else {
                ++it;
            }
        }
    }

//Function to close the restaurant
    bool closeRestaurant() {
        if (!orders.empty() || !reservations.empty()) {
            cout << "There are still active orders or reservations. Please complete or cancel all orders and reservations before closing the restaurant." << endl;
            return false;
        }
        cout << "Restaurant is now closed. Goodbye!" << endl;
        return true;
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
        cout << "3. Take an order" << endl;
        cout << "4. Serve order" << endl;
        cout << "5. Calculate total for the order and Pay" << endl;
        cout << "6. Close Restaruant (Exit)" << endl;
        cout << "7. View reservations (Diagnostic)" << endl;
        cout << "8. View tables (Diagnostic)" << endl;
        cout << "9. See menu (Diagnostic)" << endl;
        cout << "10. View orders (Diagnostic)" << endl;
        cout << "11. Exit" << endl;
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
                messiJoes.takeOrder();
                break;
            case 4:
                messiJoes.serveOrder();
                break;
            case 5:
                messiJoes.calculateBill();
                messiJoes.removeReservation(); // Remove the reservation after payment is completed
                messiJoes.removeOrder(); // Remove the order after payment is completed
                break;
            case 6:
                if (!messiJoes.closeRestaurant()) {
                    choice = 0; // Keep the menu open if closing is not allowed
                }
                break;
            case 7:
                messiJoes.viewReservations();
                break;
            case 8:
                messiJoes.viewTables();
                break;
            case 9:
                messiJoes.seeMenu();
                break;
            case 10:
                messiJoes.viewOrders();
                break;
            case 11:
                cout << "Thank you for visiting MessiJoes!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6 && choice != 11);
    return 0;
}