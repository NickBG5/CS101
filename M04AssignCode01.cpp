#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Program name: M04AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 4/7/2026
* Purpose: Write a program that takes in a text file from a tourney, reads the username and score, and
* display the average score and the gold, silver, and bronze medal winners at the end of the program
*/

int main() {
    string username, usernameFirstPlace, usernameSecondPlace, usernameThirdPlace;
    int score, totalEntries = 0, firstPlaceScore = 0, secondPlaceScore = 0, thirdPlaceScore = 0;
    double averageScore = 0.0;
    ifstream tourneyResultsFile("scores.txt");

    if (!tourneyResultsFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (tourneyResultsFile >> username >> score) {
        totalEntries++;
        averageScore += score;

        if (score > firstPlaceScore) {
            usernameThirdPlace = usernameSecondPlace;
            usernameSecondPlace = usernameFirstPlace;
            usernameFirstPlace = username;

            thirdPlaceScore = secondPlaceScore;
            secondPlaceScore = firstPlaceScore;
            firstPlaceScore = score;
        } else if (score > secondPlaceScore) {
            usernameThirdPlace = usernameSecondPlace;
            usernameSecondPlace = username;
            
            thirdPlaceScore = secondPlaceScore;
            secondPlaceScore = score;
        } else if (score > thirdPlaceScore) {
            usernameThirdPlace = username;

            thirdPlaceScore = score;
        }
    }

    if (totalEntries > 0) {
        averageScore /= totalEntries;
    }

    tourneyResultsFile.close();

    cout << "The gold medal winner is " << usernameFirstPlace << " with a score of " << firstPlaceScore << endl;
    cout << "The silver medal winner is " << usernameSecondPlace << " with a score of " << secondPlaceScore << endl;
    cout << "The bronze medal winner is " << usernameThirdPlace << " with a score of " << thirdPlaceScore << endl;
    cout << "The average score of the tournament is " << averageScore << endl;
    cout << "Congratulations to the winners! See you at the next tournament." << endl;

    return 0;
}