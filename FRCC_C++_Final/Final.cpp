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
// string allows string functions such as examining them char by char
#include <string>
// fstream allows access to both read and write of files
#include <fstream>

// using standard namespace allows us to omit 'std' in front of functions like cout and cin
using namespace std;

// declare new functions
int countLines(ifstream&);
void openFile (ifstream&, string);
void displayMenu (ifstream&, string [], double []);
void writeToReceipt (ifstream &menuFile, ofstream &receiptFile, string itemNames[], double itemPrices[]);

// global vars
const string menuPricesFile = "qbc_menu_prices.txt";
const string receiptOutputFile = "qbc_sales_receipt.txt";

// main serves as the driver code for this program. This is where we handle input from the user and call the display
// menu and print receipt functions based on logic done in the main function
int main() {
    // create file objects
    ifstream menuFile;
    ofstream receiptFile;

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
    if (orderInquiry == 'n') {
        cout << "No receipt required. Thanks!\n";
        exit(1);
    }
    // create parallel arrays to store the name of the item and the price of the item using the value from countLines
    string itemNames [countLines(menuFile)];
    double itemPrices [countLines(menuFile)];
    // call the display menu function to call it the first time
    displayMenu(menuFile, itemNames, itemPrices);

    // start an order
    writeToReceipt(menuFile, receiptFile, itemNames, itemPrices);

    // since main is required to return an integer value, returning zero effectively exits the program cleanly
    return 0;
}

// this function counts the lines in the menu text file such that we can use that number to create arrays containing the items
int countLines (ifstream& menuFile) {
    // open the file
    openFile(menuFile, menuPricesFile);
    // create string to store current line in
    string currentLine;
    // create int to store number of lines
    int menuFileLines = 0;
    // while we continue to get a next line ...
    while (getline(menuFile, currentLine)) {
        // increment the counter variable
        menuFileLines++;
    }
    menuFile.close();
    return menuFileLines;
}

// openFile() simply opens an INPUT file so it can be passed into further functions
void openFile(ifstream& file, string name) {
    // open the given file
    file.open(name);
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
    int indexCounter = 0;
    // open the passed in file
    openFile(menuFile, menuPricesFile);
    // while we are still getting new lines ...
    while (getline (menuFile, currentLine)) {
        itemNames[indexCounter] = "";
        tempPrice = "";
        // ... start iterating through the characters in the currentLine
        for (int index = 0; index < currentLine.size(); index++) {
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
        itemPrices[indexCounter] = (stod((tempPrice)));
        // after every currentLine is processed, print out the currentLine with the appropriate item number, name and price,
        // formatting with the \t (tab stop) character.
        cout << "| " << indexCounter+1 << ". " << itemNames[indexCounter] << "\t $" << itemPrices[indexCounter] << " |\n";
        // increment the counter for the parallel arrays and length of the menu
        indexCounter++;
    }
    // display the bottom line of the menu board
    cout << "------------------------\n";
    menuFile.close();
}

void writeToReceipt (ifstream& menuFile, ofstream& receiptFile, string itemNames[], double itemPrices[]) {

    // the lines integer is how long the menu is, because it is referenced several times in this file for formatting
    const int lines = countLines(menuFile);

    // create string to store selection inquiry
    int selectionInquiry;

    // create a boolean to control the looping of the order tabulation
    char continueOrdering;

    // open the receipt file because the open file function only opens input files, since we only open the output
    // function to write the receipt and to read it(or create one)
    receiptFile.open(receiptOutputFile);

    // start writing the header to the file
    receiptFile << "\tJACE'S COFFEE SHOP\n";
    receiptFile << "\tSALES RECEIPT\n";
    receiptFile << "Owner: Jace Simons\n 123-456-7890";
    receiptFile << "------------------------\n";

    // create receipt vars
    double subtotal;
    double tax;

    while (tolower(continueOrdering) == 'y') {
        // prompt user
        cout << "Please make a selection ( 1 - " << lines << " ): \n";
        // store selection
        cin >> selectionInquiry;

        while (selectionInquiry <= 0 || selectionInquiry >= lines) {
            cout << "Invalid selection; please input an integer 1 - " << lines << endl;
            cin.clear();
            cin >> selectionInquiry;
        }

        // based on the selection, start tabulating the order
        int quantityInquiry;
        cout << "How many " << itemNames[selectionInquiry-1] << " (s) do you want?\n";
        cin >> quantityInquiry;

        while (quantityInquiry < 0 || quantityInquiry > lines) {
            cout << "Invalid quantity. Please input an integer greater than 0.\n";
            cin.clear();
            cin >> quantityInquiry;
        }

        cout << quantityInquiry << "\t" << itemNames[selectionInquiry-1] << "\t" << itemPrices[selectionInquiry-1] * quantityInquiry << endl;

        cout << "Anything else I can get for you ( y/n )?\n";
        cin >> continueOrdering;
    }
    receiptFile << "------------------------\n";
    receiptFile << "Subtotal: " <<

}