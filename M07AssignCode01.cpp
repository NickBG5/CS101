/* Program name: M07AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 4/30/2026
* Purpose: Define a struct computerType to store the following data about a computer: 
* Manufacturer (string), model type (string), processor type (string), RAM (int) in GB, hard drive size (int) in GB, year when computer was built (int), and price (double)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct computerType {
    string manufacturer;
    string modelType;
    string processorType;
    int ramGB;
    int hardDriveGB;
    int yearBuilt;
    double price;
};

void writeComputerInfoToFile(const computerType& computer) {
    ofstream outFile("computerInfo.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    outFile << "Manufacturer: " << computer.manufacturer << endl;
    outFile << "Model Type: " << computer.modelType << endl;
    outFile << "Processor: " << computer.processorType << endl;
    outFile << "RAM: " << computer.ramGB << " GB" << endl;
    outFile << "Hard Drive Size: " << computer.hardDriveGB << " GB" << endl;
    outFile << "Year Built: " << computer.yearBuilt << endl;
    outFile << "Price: $" << fixed << setprecision(2) << computer.price << endl;
    outFile.close();
}

int main() {
    computerType myComputer;

    cout << "Enter the computer manufacturer: ";
    cin >> myComputer.manufacturer;
    cout << "Enter the computer model type: ";
    cin >> myComputer.modelType;
    cout << "Enter the computer processor type: ";
    cin >> myComputer.processorType;
    cout << "Enter the computer RAM (GB): ";
    cin >> myComputer.ramGB;
    cout << "Enter the computer hard drive size (GB): ";
    cin >> myComputer.hardDriveGB;
    cout << "Enter the computer year built: ";
    cin >> myComputer.yearBuilt;
    cout << "Enter the computer price: ";
    cin >> myComputer.price;

    writeComputerInfoToFile(myComputer);
    return 0;
}