/*

Program Title: University Meal Plan Selector

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/1/21

Brief Description of this program: Menu driven program which asks the user to select a given area calculation, and then ask for the required dimensions and calculate the area of the shape
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
    int shape;
    double dimension1;
    double dimension2;
    // display menu
    cout << "        Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1 - 4)" << endl;
    // store input and validate
    while (!(cin >> shape) || !(shape >= 1 && shape <= 4)) {
        cout << "Invalid inout. Please input a number between 1 and 4" << endl;
        cin.clear();
    }

    // if the input is 4, quit
    if (shape == 4) {
        return;
    }

    // prompt for dimensions
    cout << "Input dimension 1" << endl;
    // store input and validate it
    while (!(cin >> dimension1) || (dimension1 < 0)) {
        cout << "Invalid input. Please input an number above 0." << endl;
        cin.clear();
    }
    // if the user selected a rectangle or triangle, we need to get the second dimension
    if (shape == 2 || shape == 3) {
        cout << "Inout dimension 2" << endl;
        // store input and validate it
        while (!(cin >> dimension2) || (dimension2 < 0)) {
            cout << "Invalid input. Please input a number above 0." << endl;
            cin.clear();
        }
    }

    // switch statement which does the math and prints it out
    switch (shape) {
        case 1:
            cout << "The area of this circle is: " << (3.14159) * pow((dimension1),2);
            break;
        case 2:
            cout << "The area of this rectangle is: " << (dimension1) * (dimension2);
            break;
        case 3:
            cout << "The area of this triangle is: " << ((dimension1) * (dimension2)) * 0.5;
            break;
        case 4:
            break;
    }
}