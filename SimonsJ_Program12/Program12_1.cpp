/*

Program Title: Alphabetic Telephone Number Translator

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: DATE

Brief Description of this program: Since companies use numbers like 555-GET-FOOD as an easy to remember translation of
 their number, this program converts that back into a phone number so you can call it. For example 555-GET-HELP translates
 to 555-438-3663.

*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
void processNumber (string phoneNumber);
char translateLetterToDigit (char ch);

int main() {
    // create input var
    string input;

    // prompt user
    cout << "Go ahead and input a phone number you want to translate: \n";

    // and subsequently store the input
    cin >> input;

    // then call the function to begin processing the string
    processNumber(input);

    // return 0 exits the program
    return 0;
}

// define the function
void processNumber (string phoneNumber) {
    // first create an integer to store the length of the string
    int n = phoneNumber.length();
    // make a new string to hold the translated number
    string translatedNumber;
    // begin iterating through the characters in the string
    for (int index = 0; index < n; index++) {
        // if the character IS a digit or IS a dash ...
        if (isdigit(phoneNumber[index]) || phoneNumber[index] == '-') {
            // ... simply concatenate that character to the new string, because we want to keep those
            translatedNumber += phoneNumber[index];
        }
        // if it's neither of those things, that means its a number (since we're asking the user to input a phone number)
        else {
            // in this case, concatenate the respective digit returned by the translateLetterToDigit function defined below
            translatedNumber += (translateLetterToDigit(phoneNumber[index]));
        }
    }
    // finally, print out the translated string
    cout << "Translated Number: " << translatedNumber;
}

// define translateLetterToDigit function
char translateLetterToDigit (char ch) {
    // switch statement which uses the inputted character
    // if its a b or c it returns 2 AS A CHARACTER so that it appropriately concatenates the digit
    switch (ch) {
        case 'A':
        case 'B':
        case 'C':
            return '2';
        // if its a d e or f return 3 and so on
        case 'D':
        case 'E':
        case 'F':
            return '3';
        case 'G':
        case 'H':
        case 'I':
            return '4';
        case 'J':
        case 'K':
        case 'L':
            return '5';
        case 'M':
        case 'N':
        case 'O':
            return '6';
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            return '7';
        case 'T':
        case 'U':
        case 'V':
            return '8';
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return '9';
    }
}