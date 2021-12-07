/*

Program Title: Astronomy Helper

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/1/21

Brief Description of this program: Menu driven program that displays information about the selected planet
*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new function prototype
void displayMenu ();

int main() {
    displayMenu();
    // return 0 exits the program
    return 0;
}

// define function
void displayMenu () {
    // create inputs
    int planet;
    // display menu
    cout << "        Select a Planet" << endl;
    cout << "1. Mercury" << endl;
    cout << "2. Venus" << endl;
    cout << "3. Earth" << endl;
    cout << "4. Mars" << endl;
    cout << "5. Exit the program" << endl;
    cout << "Enter your selection" << endl;
    // store input and validate
    while (!(cin >> planet) || !(planet >= 1 && planet <= 5)) {
        cout << "Invalid input. Please input a number between 1 and 5" << endl;
        cin.clear();
    }

    // switch statement which prints out the stats of the given planet
    switch (planet) {
        case 1:
            cout << "MERCURY" << endl;
            cout << "Average distance from the Sun: 57.9 million kilometers" << endl;
            cout << "Mass: 3.31 * 10^23kg" << endl;
            cout << "Surface Temperature: -173 to 430 degrees Celsius" << endl;
            break;
        case 2:
            cout << "VENUS" << endl;
            cout << "Average distance from the Sun: 108.2 million kilometers" << endl;
            cout << "Mass: 4.87 * 10^24kg" << endl;
            cout << "Surface Temperature: 472 degrees Celsius" << endl;
            break;
        case 3:
            cout << "EARTH" << endl;
            cout << "Average distance from the Sun: 149.6 million kilometers" << endl;
            cout << "Mass: 5.967 * 10^24kg" << endl;
            cout << "Surface Temperature: -50 to 50 degrees Celsius" << endl;
            break;
        case 4:
            cout << "MARS" << endl;
            cout << "Average distance from the Sun: 227.9 million kilometers" << endl;
            cout << "Mass: 0.6424 * 10^24kg" << endl;
            cout << "Surface Temperature: -140 to 20 degrees Celsius" << endl;
            break;
        case 5:
            break;
    }
}