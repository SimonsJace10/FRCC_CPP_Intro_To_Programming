/*

Program Title: Word Separator

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/6/21

Brief Description of this program: Given an input string of a sentence in which all the words run together but the first
 letter of each is capitalized, the program separates the words and forms a proper sentence.

*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>
#include <string>
#include <cctype>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
void separateWords(string str);

int main () {
    // create input string
    string input;
    // prompt user
    cout << "Go ahead and input a sentence with all the words run together, and it will return as a proper sentence." << endl;
    // store input
    cin >> input;
    // call function and print output
    cout << "Input: " << input << endl;
    separateWords(input);

    // main is of the int return type and therefore returning 0 exits the program
    return 0;
}

// define new function
void separateWords (string str) {
    // first create a variable to store the length of the string
    int n = str.length();
    // next make a new string which will store the characters that comprise the new string after being processed below
    string processedString = "";
    // begin iterating through the string
    for (int index = 0; index < n; index++) {
        // if the index is 0, meaning the first character of the string, we want to keep it uppercase.
        if (index == 0) {
            // concatenate the character as is because it should be passed in as uppercase
            processedString += str[index];
            // and skip to the next index in the for loop
            continue;
        }
        // if the character at index 'index' is uppercase
        if (isupper(str[index])) {
            // concatenate a space...
            processedString += ' ';
            // as well as the lowercase version of that character
            processedString += tolower(str[index]);
        }
        // if the character at 'index' isn't uppercase...
        else {
            // simply concatenate it as is
            processedString += tolower(str[index]);
        }
    }
    // finally, print out the new, processed string
    cout << "Output: " << processedString << endl;
}