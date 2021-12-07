//
// Created by stick on 12/1/2021.
//

/*

Program Title: TEMPLATE

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: DATE

Brief Description of this program: Generates random number

*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
int generateRandom();

// define generateRandom function, which uses seeded randomness to create a random number between 0 and 100
int generateRandom() {
    // seeding with the current time is a good way to achieve psuedo randomness.
    srand(time(0));
    // the number is the random number modulo 100, which will make the number between 0 and 2, then adding 1 will adjust this to 1 to 3
    int num = rand() % 100;
    // return the random number
    return num;
}

int main() {
    // create input
    cout << "Your random number is " << generateRandom() << endl;

    // return 0 exits the program
    return 0;
}