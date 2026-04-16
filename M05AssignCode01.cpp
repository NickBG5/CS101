#include <iostream>
#include <string>
#include <cctype>


using namespace std;


/* Program name: M05AssignCode01.cpp
* Author: Nicholas Garcia
* Date last updated: 4/14/2026
* Purpose: Write a program that prompts the user to input a sequence of characters and output the number of vowels. 
*There should be a function that takes the cahracters of the sequence to check if it's a vowel and return true or false
*/
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string input;
    int vowelCount = 0;

    cout << "Enter a sequence of characters: ";
    getline(cin, input);

    for(char c : input) {
        if(isVowel(c)) {
            vowelCount++;
        }
    }
    cout << "Number of vowels: " << vowelCount << endl;
    return 0;
}