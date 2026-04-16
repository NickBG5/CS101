#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* Program name: M03AssignCode02.cpp
*  Author: Nicholas Garcia
*  Date last updated: 3/31/2026
* Purpose: Read data from ghost.txt file and read the event code and the number of times that an even occurred. 
* Then calculate an overall haunting score for the ghost hunt. 
* If the score is greater than 15, then you should display the message "This place is haunted." 
* Otherwise, the program should display "This place is probably not haunted."
*/

using namespace std;

int main () {
    ifstream myFile;
    int eventInstances;
    char eventCode;

    for(int i = 0; i < 4; i++) {
    int hauntingScore = 0;
    string myText, fileName;

    //I had my ghost.txt files in a separate folder from where the program was located. Then I wanted to iterate through all files in the folder
    //My assumption is the first file would be ghosts.txt and the rest would have ghosts1.txt, ghosts2.txt, ghosts3.txt, etc.
    //The only downside to my code is that I had to hardcode how many files I had in the folder
    if(i == 0) {
        fileName = "../CS101/GhostTextFolder/ghosts.txt";
    } else {
        fileName = "../CS101/GhostTextFolder/ghosts" + to_string(i) + ".txt";
    }
    myFile.open(fileName);
    if(!myFile.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return 1;
    }
    
    cout << "Analyzing Ghost Hunt Data..." << endl;

    while (getline(myFile, myText)) {
        stringstream ghostInfo(myText);
        if(!(ghostInfo>>eventCode >> eventInstances)) continue; // Skip lines that don't have the correct format

        ghostInfo >> eventCode >> eventInstances;

        switch (eventCode) {
            case 'E':
                hauntingScore += eventInstances * 3;
                cout << "Found " << eventInstances << " instances of EVP(Electronic Voice Phenomenon)." << endl;
                break;
            case 'S':
                hauntingScore += eventInstances * 1;
                cout << "Found " << eventInstances << " instances of shadows or orbs." << endl;
                break;
            case 'F':
                hauntingScore += eventInstances * 2;
                cout << "Found " << eventInstances << " instances of Footsteps." << endl;
                break;
            case 'A':
                hauntingScore += eventInstances * 5;
                cout << "Found " << eventInstances << " instances of Full Body Apparitions." << endl;
                break;
            case 'O':
                hauntingScore += eventInstances * 5;
                cout << "Found " << eventInstances << " instances of Objects moving on their own." << endl;
                break;
            case 'D':
                hauntingScore += eventInstances * 3;
                cout << "Found " << eventInstances << " instances of Doors shutting on their own." << endl;
                break;
            case 'T':
                hauntingScore += eventInstances * 2;
                cout << "Found " << eventInstances << " instances of ThermoCamera hot or cold spots." << endl;
                break;
            default:
                cout << "Invalid event code." << endl;
                return 1;
        }
    }

    if(hauntingScore > 15) {
        cout << "The haunting score for this place is " << hauntingScore << "." << endl;
        cout << "This place is haunted." << endl;
    } else {
        cout << "The haunting score for this place is " << hauntingScore << "." << endl;
        cout << "This place is probably not haunted." << endl;
    }
    
    cout << "Great job! On to the next one." << endl;
    myFile.close();
    myFile.clear();
    }
    return 0;
}