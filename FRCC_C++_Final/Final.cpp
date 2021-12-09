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
void displayMenu (ifstream&);
void openFile (ifstream&);
void tab (int menuLength, ifstream&);
void salesReceipt ();

// main serves as the driver code for this program. This is where we handle input from the user and call the display
// menu and print receipt functions based on logic done in the main function
int main() {
//    int strIndex;
//    int pos = 0;
//    string str1 = "test haha";
//    string str2 = "test";
//    while (strIndex = str1.find(str2, pos) != string::npos) {
//        cout << "found at " << strIndex;
//        pos = strIndex + 1;
//    }

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

    // open file to pass to functions
    // create file object
    ifstream menuFile;
    openFile(menuFile);

    // display the menu in this case, because if the user said no then the program has already exited
    displayMenu(menuFile);

    // return 0 exits the program
    return 0;
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

void displayMenu (ifstream& menuFile) {
    // The next block handles input from file 'qbc_menu_prices.txt'
    // variable to store the number of menu items
    int menuLength = 1;
    // declare string variable to relay lines from file
    string line;

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
    menuFile.close();
    tab(menuLength, menuFile);
}

void tab (int menuLength, ifstream& menuFile) {
    // create inquiry var to store selection
    string selectionInquiry;
    // prompt user
    cout << "Please make a selection [ type the name of the item ]\n";
    // take in and store input
    cin >> selectionInquiry;

    string line;
    string itemName;
    string itemPrice;
    double price;
    int strIndex;
    int pos = 0;
    cout << selectionInquiry;
    openFile(menuFile);
    while (getline(menuFile, line)) {
        // ...
        itemName = "", itemPrice = "";
        cout << line;
        while (strIndex = line.find(selectionInquiry, pos) != string::npos) {
            itemName += selectionInquiry;
            cout << "found at " << strIndex;
            pos = strIndex + 1;
            for (int index = 0; index < line.length(); index++) {
                if (isdigit(line[index]) || line[index] == '.') {
                    itemPrice += line[index];
                }
                else {
                    continue;
            }
        }
    }

    price = stod(itemPrice);

        // begin order placement
        double itemQuantityInquiry = 0;
        cout << "How many " << itemName << " would you like?\n";
        cin >> itemQuantityInquiry;

        cout << itemQuantityInquiry << " of " << itemName << " added to your order for " << price * itemQuantityInquiry;
    }
}

void displaySalesReceipt() {
    // this function handles printing a receipt based on the order from the user
}