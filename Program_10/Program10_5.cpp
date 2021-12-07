/*

Program Title: Program 10_5: Sales Report

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 11/17/21

Brief Description of this program: Prints out sales report of car dealer

*/

// including the iostream allows access to the flow of input/output through the system
#include <iostream>
// fstream allows access to files (read & write)
#include <fstream>

// using namespace std allows us to omit std:: in front of certain calls
using namespace std;

// declare function
void printReport ();

// main is the entry point for the program
int main() {
    printReport();
    
    // returning 0 exits the program
    return 0;
} 

void printReport () {
    // declare vars
    int employeeID;
    double totalPerPerson;
    double total;
    double input;
    // take in the file "numbers.dat"
    ifstream inFile;
    // open the file
    inFile.open ("golf.txt");
    // if it fails, report this as such
    if (inFile.fail()) {
        cout << "Could not open file.\n";
        exit(1);
    }

    // start by printing out the header
    cout << "Brewster's Used Cars, Inc. Sales Report\n";
    cout << "Salesperson ID     Sale Amount\n";

    // while the program isn't at th end of the file ...
    while (!inFile.eof()) {
        // ... if the next line is in between 100 and 1000, it's an employee ID
        if (input >= 100 && input < 1000) {
            // set it equal and print
            employeeID = input;
            cout << employeeID << endl;
        }
        else {
            // otherwise, print the number out and add the input to the totals
            cout << "$" << input << endl;
            totalPerPerson += input;
            total += input;
        }

        if (input >= 100 && input < 1000 && input != employeeID) {
            // if the input isn't the previous employyeID and is between 100 and 1000, set it as the new employee id
            cout << "Total sales for this salesperson: " << totalPerPerson;
            totalPerPerson = 0;
        }
    }
    // close the file
    inFile.close();
}