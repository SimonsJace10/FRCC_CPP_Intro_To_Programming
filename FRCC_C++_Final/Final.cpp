/*

Program Title: FRCC C++ Final

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/8/21

Brief Description of this program: This is a program for a hypothetical coffee shop. They sell coffee, tea, bagels, milk
 and donuts. This is a menu-driven program in which the user makes a selection, and at the end they are given a receipt.

*/

// including io stream allows the program to access the flow of input and output through the system
#include <iostream>
#include <string>
#include <fstream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
int countLines(ifstream&);
void openFile (ifstream&);
void displayMenu (ifstream&, string [], double []);

// main serves as the driver code for this program. This is where we handle input from the user and call the display
// menu and print receipt functions based on logic done in the main function
int main() {
    // create file object
    ifstream menuFile;

    // create char to store input into
    char orderInquiry;
    // greet user
    cout << "Welcome to Jace's Coffee Shop! Would you like to place an order? (y/n)\n";
    // store input
    cin >> orderInquiry;
    // validate input for starting an order. While the input isn't y and it isn't n ...
    while (tolower(orderInquiry) != 'y' && tolower(orderInquiry) != 'n') {
        // ... tell user,
        cout << "Invalid input- please input y or n.\n";
        // clear the input buffer,
        cin.clear();
        // and re-intake input
        cin >> orderInquiry;
    }
    // create parallel arrays to store the name of the item and the price of the item using the value from countLines
    string itemNames [countLines(menuFile)];
    double itemPrices [countLines(menuFile)];

    displayMenu(menuFile, itemNames, itemPrices);
}

// this function counts the lines in the menu text file such that we can use that number to create arrays containing the items
int countLines (ifstream& menuFile) {
    // open the file
    openFile(menuFile);
    // create string to store current line in
    string currentLine;
    // create int to store number of lines
    int menuFileLines = 0;
    // while we continue to get a next line ...
    while (getline(menuFile, currentLine)) {
        // increment the counter variable
        menuFileLines++;
    }
    return menuFileLines;
}

// openFile() simply opens a file so it can be passed into further functions
void openFile(ifstream& file) {
    // open the given file
    file.open("qbc_menu_prices.txt");
    // if it fails, report it as such
    if (file.fail()) {
        cout << "Failed to open file.\n";
        exit (1);
    }
}

void displayMenu (ifstream& menuFile, string itemNames[], double itemPrices[]) {
    // populate the arrays
    // begin printing out the menu, starting with the header
    cout << "       ~~ MENU ~~\n";
    cout << "------------------------\n";

    // create temporary name and price variables to store the name and price extracted from a given line of the menu file
    string tempPrice;
    string currentLine;
    // the index counter serves to count along the side of the menu (1. coffee 2. tea, etc.) and to assign the values to
    // the proper indexes of the parallel arrays
    int indexCounter;
    // open the passed in file
    openFile(menuFile);
    // while we are still getting new lines ...
    while (getline (menuFile, currentLine)) {
        itemNames[indexCounter] = "";
        itemPrices[indexCounter] = 0.0;
        // ... start iterating through the characters in the currentLine
        for (int index = 0; index < currentLine.size()-1; index++) {
            // if it's a letter ...
            if (isalpha(currentLine[index]) && !isspace(currentLine[index])) {
                // ... concatenate the letter to the name of the item
                itemNames[indexCounter] += currentLine[index];
            }
                // if it's a digit or a period ...
            else if (isdigit(currentLine[index]) || currentLine[index] == '.') {
                // concatenate it to the string price of the item
                tempPrice += currentLine[index];
            }
                // if it's a space or newline ...
            else if (isspace(currentLine[index]) || currentLine[index] == '\n') {
                // iterate
                continue;
            }
        }
        itemPrices[indexCounter]= stod((tempPrice));
        // after every currentLine is processed, print out the currentLine with the appropriate item number, name and price,
        // formatting with the \t (tab stop) character.
        cout << "| " << indexCounter << ". " << itemNames[indexCounter] << " \t $" << itemPrices[indexCounter] << " |\n";
        // increment the counter for the parallel arrays and length of the menu
        indexCounter++;
    }
    // display the bottom line of the menu board
    cout << "------------------------\n";
    menuFile.close();
}