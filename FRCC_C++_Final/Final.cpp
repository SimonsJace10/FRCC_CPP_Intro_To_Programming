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

// declare and define menu item class
//class menuItem {
//public:
//    string name;
//    double price;
//};

// declare new functions
void displayMenu ();
void tab ();
void salesReceipt ();

// main serves as the driver code for this program. This is where we handle input from the user and call the display
// menu and print receipt functions based on logic done in the main function
int main() {
    // create vars
    char placeOrderInquiry;

    // prompt user
    cout << "Would you like to place and order? [y or n]\n";
    // take input and store in placeOrderInquiry
    cin >> placeOrderInquiry;

    // input validation
    // while the input isn't y or n ...
    while (tolower(placeOrderInquiry) != 'y' && tolower(placeOrderInquiry) != 'n') {
        // ... tell the user to enter a valid input ...
        cout << "Invalid input, please input either y or n.\n";
        // ... clear the input buffer
        cin.clear();
        // re-take in the input
        cin >> placeOrderInquiry;
    }
    // if the input is no, exit the program
    if (placeOrderInquiry == 'n') {
        // say goodbye
        cout << "No receipt required. Thanks!";
        // exit program
        exit(1);
    }
    // display the menu in this case, because if the user said no then the program has already exited
    displayMenu();

    // return 0 exits the program
    return 0;
}

void displayMenu () {
    // The next block handles input from file 'qbc_menu_prices.txt'
    // variable to store the menu items
    int menuLength = 1;
    // declare string variable to relay lines from file
    string line;
    // create object to handle the file
    ifstream menuFile;
    // open the file
    menuFile.open("qbc_menu_prices.txt");
    // if it fails, report it as such
    if (menuFile.fail()) {
        cout << "Failed to open file.\n";
        exit (1);
    }

    // creating strings for the strings taken in from the file
    string itemName;
    string itemPrice;
    // begin printing out the menu, starting with the header
    cout << "       ~~ MENU ~~\n";
    cout << "------------------------\n";


    // while we are still getting new lines ...
    while (getline (menuFile, line)) {
        // ...
        itemName = "", itemPrice = "";
        for (int index = 0; index < line.length(); index++) {
            // if it's a letter ...
            if (isalpha(line[index]) && !isspace(line[index])) {
                // ... concatenate the letter to the name of the item
                itemName += line[index];
            }
            // if it's a digit or a period ...
            else if (isdigit(line[index]) || line[index] == '.') {
                // concatenate it to the string price of the item
                itemPrice += line[index];
            }
            // if it's a space or newline ...
            else if (isspace(line[index]) || line[index] == '\n') {
                // iterate
                continue;
            }
        }
        // after every line is processed, print out the line with the appropriate item number, name and price,
        // formatting with the \t (tab stop) character.
        cout << "| " << menuLength << ". " << itemName << " \t $" << itemPrice << " |\n";
        // increment the length of the menu
        menuLength++;
    }
    // display the last line of the menu
    cout << "------------------------\n";
    //tab(menuLength);
}

void tab () {
    // create inquiry var to store selection
    int selectionInquiry;
    // prompt user
    cout << "Please make a selection.\n";
    // take in and store input
    cin >> selectionInquiry;

    // input validation
    // while the input is less than 0 or more than menu length ...
    while (selectionInquiry <= 0 || selectionInquiry > 5) {
        // ... tell the user ...
        cout << "Please input a valid selection [ 1 - " << 5 << " ]\n";
        // ... clear the input buffer
        cin.clear();
        // re-intake input
        cin >> selectionInquiry;
    }
    // begin order placement
    int itemCount;
    cout << "How many would you like?\n";

}

void salesReceipt() {
    // this function handles printing a receipt based on the order from the user
}