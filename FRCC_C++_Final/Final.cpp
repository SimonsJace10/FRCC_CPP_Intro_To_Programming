/*

Program Title: FRCC C++ Final

Programmer: Simons, Jace

Course: CSC119-145 Introduction to Programming C++ Fall 2021

Submission Date: 12/8/21

Brief Description of this program: This is a program for a hypothetical coffee shop. They sell items listed in the
 qbc_menu_prices.txt file. This is a menu-driven program in which the user places an order, and at the end they are
 given a receipt.

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
void writeToSalesReceipt (ifstream &menuFile, ofstream &receiptFile, string itemNames[], double itemPrices[]);
void displaySalesReceipt ();

// global vars for the names of the files are appropriate here because they are used all over the code in calls to openFile();
const string menuPricesFile = "qbc_menu_prices.txt";
const string receiptOutputFile = "qbc_sales_receipt.txt";

// main serves as the driver code for this software. This is our entry point for placing an order.
// in main we just do some input validation on the question to the user of whether they want to start an order or not,
// and then dive into the sales receipt function, which is the order driver
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
    // if the user inputs 'n' ...
    if (orderInquiry == 'n') {
        // ... print the statement "No receipt required. Thanks!"
        cout << "No receipt required. Thanks!\n";
        // exiting with a code differentiates it from an error or an exit with 0 like a normal main exit. It also serves
        // the purpose of skipping the rest of  the code in main before closing.
        exit(1);
    }
    // create parallel arrays to store the name of the item and the price of the item using the value from countLines
    string itemNames [countLines(menuFile)];
    double itemPrices [countLines(menuFile)];

    // start an order and write it to the receipt file
    writeToSalesReceipt(menuFile, receiptFile, itemNames, itemPrices);

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
    // close the file for memory management
    menuFile.close();
    // return the number of lines as an integer
    return menuFileLines;
}

// openFile() simply opens an INPUT file so it can be passed into further functions
void openFile(ifstream& file, string name) {
    // open the given file
    file.open(name);
    // if it fails to open ...
    if (file.fail()) {
        // ... tell the user which file failed,
        cout << "Failed to open file: " <<  name << endl;
        // and exit with a special code to differentiate it from normal exit codes
        exit (1);
    }
}

// displayMenu() does exactly what the name says - it reads all data from the qbc_menu_prices.txt file and processes
// them, turning it into a legible menu for the user. This function also handles
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

void writeToSalesReceipt (ifstream& menuFile, ofstream& receiptFile, string itemNames[], double itemPrices[]) {

    // the lines integer is how long the menu is, because it is referenced several times in this file for formatting
    const int lines = countLines(menuFile);

    // create string to store selection inquiry
    int selectionInquiry;

    // create a boolean to control the looping of the order tabulation
    char continueOrdering = 'y';

    // open the receipt file because the open file function only opens input files, since we only open the output
    // function to write the receipt and to read it(or create one)
    receiptFile.open(receiptOutputFile);

    // start writing the header to the file
    receiptFile << "\tJACE'S COFFEE SHOP\n";
    receiptFile << "\tSALES RECEIPT\n";
    receiptFile << "  Owner: Jace Simons\n  123-456-7890\n\n";
    receiptFile << "------------------------\n\n";

    // create receipt vars
    double subtotal;
    double tax;

    while (tolower(continueOrdering) == 'y') {
        // display the menu
        displayMenu(menuFile, itemNames, itemPrices);

        // prompt user
        cout << "\nPlease make a selection ( 1 - " << lines << " ): \n";
        // store selection
        cin >> selectionInquiry;

        while (selectionInquiry <= 0 || selectionInquiry > lines) {
            cout << "Invalid selection; please input an integer 1 - " << lines << endl;
            cin.clear();
            cin >> selectionInquiry;
        }

        // based on the selection, start tabulating the order
        int quantityInquiry;
        cout << "How many " << itemNames[selectionInquiry-1] << "(s) do you want?\n";
        cin >> quantityInquiry;

        while (quantityInquiry < 0) {
            cout << "Invalid quantity. Please input an integer greater than 0.\n";
            cin.clear();
            cin >> quantityInquiry;
        }

        receiptFile << quantityInquiry << "\t" << itemNames[selectionInquiry-1] << "\t" << itemPrices[selectionInquiry-1] * quantityInquiry << endl << endl;
        cout << quantityInquiry << " " << itemNames[selectionInquiry-1] << "s added to your order for $" << itemPrices[selectionInquiry-1] * quantityInquiry << endl;
        subtotal += itemPrices[selectionInquiry-1] * quantityInquiry;

        cout << "Anything else I can get for you ( y/n )?\n";
        cin >> continueOrdering;
        while (continueOrdering != 'y' && continueOrdering != 'n') {
            cout << "Invalid input. Please submit y or n.\n";
            cin.clear();
            cin >> continueOrdering;
        }
        if (tolower(continueOrdering) == 'n') {
            break;
        }
    }

    // add the bottom piece of the receipt to the file and calculate tax and total
    tax = subtotal * 0.08;
    receiptFile << "------------------------\n\n";
    receiptFile << "Subtotal: \t$" << subtotal << endl;
    receiptFile << "Tax: \t\t$" << tax << endl << endl;
    receiptFile << "------------------------\n\n";
    receiptFile << "Total: \t$" << subtotal + tax << endl << endl;
    receiptFile << "THANK YOU!\n";

    // call the function to display the newly written to file
    displaySalesReceipt();

    // close the file for memory management
    receiptFile.close();
}

void displaySalesReceipt () {

    // create object to intake from the receipt file
    ifstream receiptFile;

    // open the receipt file
    openFile(receiptFile, receiptOutputFile);

    // string to store current line
    string currentLine;

    // while we're still getting lines ...
    while ( getline(receiptFile, currentLine) ) {
        // ... simply print out the line and go to the next line afterwards
        cout << currentLine << endl;
    }
    // close the file for memory managemnet
    receiptFile.close();
}