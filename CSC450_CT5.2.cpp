//============================================================================
// Name        : CSC450_CT5.2.cpp
// Author      : Ari Fakhri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Method that reverses all characters in the original file
void reverseFile() {

    ifstream inputFile("CSC450_CT5_mod5.txt");

    if (!inputFile) {
        cout << "Error opening CSC450_CT5_mod5.txt" << endl;
        return;
    }

    string contents;
    char character;

    // Read every character from the file
    while (inputFile.get(character)) {
        contents += character;
    }

    inputFile.close();

    // Open the reverse file
    ofstream reverseFile("CSC450-mod5-reverse.txt");

    if (!reverseFile) {
        cout << "Error creating reverse file." << endl;
        return;
    }

    // Write characters backwards
    for (int i = contents.length() - 1; i >= 0; i--) {
        reverseFile << contents[i];
    }

    reverseFile.close();

    cout << "The reversed file was created successfully." << endl;
}

int main() {

    string userInput;

    cout << "Enter text to add to the file: ";
    getline(cin, userInput);

    // Open the original file in append mode
    ofstream outputFile("CSC450_CT5_mod5.txt", ios::app);

    if (!outputFile) {
        cout << "Error opening CSC450_CT5_mod5.txt" << endl;
        return 1;
    }

    // Add the user's text without deleting existing text
    outputFile << endl << userInput;

    outputFile.close();

    cout << "Your text was successfully added to the file." << endl;

    // Reverse the file
    reverseFile();

    return 0;
}
