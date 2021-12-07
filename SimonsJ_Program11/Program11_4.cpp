/*

Program Title: Golf Score Modification

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/1/21

Brief Description of this program: Menu driven program that either reads each player's name and stores their golf score, or that reads the contents of the hypothetical golf.dat file
*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>
#include <fstream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new function prototype
void displayMenu ();
void storeGolfScores();
void readGolfScores();

int main() {
    displayMenu();
    // return 0 exits the program
    return 0;
}

// define function
void displayMenu () {
    // create inputs
    int program;

    // display menu
    cout << "        Select a Program" << endl;
    cout << "1. Store Golf Scores" << endl;
    cout << "2. Read Golf Scores" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your selection" << endl;
    // store input and validate
    while (!(cin >> program) || !(program >= 1 && program <= 3)) {
        cout << "Invalid input. Please input a number between 1 and 5" << endl;
        cin.clear();
    }

    // switch statement which prints out the stats of the given program
    switch (program) {
        case 1:
            storeGolfScores();
            break;
        case 2:
            readGolfScores();
            break;
        case 3:
            break;
    }
}

void storeGolfScores() {
    cout << "       STORE GOLF SCORES" << endl;

    // create var
    string inputStr;

    // take in the file "numbers.dat"
    ofstream inFile;

    // open the file
    inFile.open ("golf.txt");

    // if it fails, report this as such
    if (inFile.fail()) {
        cout << "Could not open file.\n";
        exit(1);
    }

    // while the input is still going ...
    while (cin) {
        cin >> inputStr;
        inFile << inputStr << endl;
    }

    // close the file
    inFile.close();
}

void readGolfScores() {
    cout << "       READ GOLF SCORES" << endl;

    // declare vars
    string input;
    // take in the file "numbers.dat"
    ifstream inFile;
    // open the file
    inFile.open ("golf.txt");
    // if it fails, report this as such
    if (inFile.fail()) {
        cout << "Could not open file.\n";
        exit(1);
    }

    // while the file is taking in numbers ...
    while (!inFile.eof()) {
        // ... print out the line of the file ...
        cout << input;
    }
    // close the file
    inFile.close();
}