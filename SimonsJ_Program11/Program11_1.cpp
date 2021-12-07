/*

Program Title: University Meal Plan Selector

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/1/21

Brief Description of this program: Menu driven program which asks the user to select a given meal plan, and enter the number of semesters. Then, the program will tell the user how much it will cost for this meal plan.

*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
int calculateMealPlan(int price, int semesters);

int main() {
    // create inputs
    int plan;
    int semesters;
    // display menu
    cout << "Menu Selection" << endl;
    cout << "1. Plan 1: 7 meals per week for $560/semester" << endl;
    cout << "2. Plan 2: 14 meals per week for $1,095/semester" << endl;
    cout << "3. Plan 3: unlimited meals for $1500/semester" << endl;
    cout << "4. End the Program" << endl;
    cout << "Enter your Selection [ 1 - 4 ]" << endl;
    // store input and validate
    while (!(cin >> plan) || !(plan >= 1 && plan <= 4)) {
        cout << "Invalid inout. Please input a number between 1 and 4" << endl;
        cin.clear();
    }

    // prompt for semesters
    cout << "How many semesters are you planning for?" << endl;
    // store input and validate it
    while (!(cin >> semesters) || !(semesters >= 1)) {
        cout << "Invalid input. Please input an integer above 0." << endl;
        cin.clear();
    }

    switch (plan) {
        case 1:
            cout << calculateMealPlan(560, semesters) << endl;
            break;
        case 2:
            cout << calculateMealPlan(1095, semesters) << endl;
            break;
        case 3:
            cout << calculateMealPlan(1500, semesters) << endl;
            break;
        case 4:
            break;
    }

    // return 0 exits the program
    return 0;
}

int calculateMealPlan(int price, int semesters) {
    return price * semesters;
}