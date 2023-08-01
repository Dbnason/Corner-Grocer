/* 
* created by Darren Nason
* CS - 210
* Date: 08 - 01 - 2023
* Program to calculate frequencies for a shoppers cart from a .txt file
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <filesystem>
using namespace std;

class WordFrequencyMenu {
public:
WordFrequencyMenu() {
            
        // Load data from the input file into the wordFrequency map
        ifstream inputFile("/Users/DarrenNason/Desktop/Corner Grocer/CS210_Project_Three_Input_File.txt");
        if (!inputFile.good()) {
            cout << "File not found." << endl;
            return;
        }

        string word;
        while (inputFile >> word) {
            wordFrequency[word]++;
        }
        inputFile.close();
    }


// for debugging to check for the file being loaded correctly 
void printWordFrequency() {
    cout << "Word Frequency:" << endl;
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Function to display the menu to the user
void displayMenu() {
    // declare variable
    int choice;
    // do while loop to return options for user and exit program if 4 is entered
    do {
        cout << "*\t      " << "Menu Options:" << "\t" << "\t  `*" << endl;
        cout << "*******************************************" << endl;
        cout << "1. Find frequency of a specific word" << endl;
        cout << "2. Print the list with numbers of all items" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "*******************************************" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Switch statement to navigate to functions inside of program
        switch (choice) {
            case 1:
            system("clear");
            findFrequencyOfWord();
            break;
            case 2:
            system("clear");
            printFrequencyList();
            break;
            case 3:
            system("clear");
            printHistogram();
            break;
            case 4:
            cout << endl;
            cout << "Exiting the program...Thanks for shopping!" << endl;
            break;
            default:
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
        }
    } while (choice != 4);
}

private:
    // creates the map
    map<string, int> wordFrequency;

    // function to find the word frequency inside of the .txt file based upon what word the user inputs
    void findFrequencyOfWord() {
        string word;
        cout << "-------------***********--------------" << endl;
        cout << "Enter the word you wish to look for: ";
        cin.ignore();
        getline(cin, word);

        map<string, int>::iterator it = wordFrequency.find(word);
        if (it != wordFrequency.end()) {
            cout << "Frequency of " << word << ": " << it->second << endl;
            cout << "-------------***********--------------" << endl;
            cout << endl;
        } else {
            cout << "'" << word << "' not found in the input file." << endl;
        }
    }

    // function to display all results inside of the .txt file 
    void printFrequencyList() {
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    cout << "   -- * --  " << "All items checked out" << "   -- * --" << endl;
    cout << "-----------------------------------------------" << endl;
        for (map<string, int>::const_iterator it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    cout << "-----------------------------------------------" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    cout << endl;
    }
    // function to display the results in the .txt file in a histogram format
    void printHistogram() {
    cout << "----------------------------------------------" << endl;
    cout << "____________" << "Histogram of all items" << "____________" << endl;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
        for (map<string, int>::const_iterator it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------" << endl;
        cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
        cout << endl;


    }
};

// starting point for the program
int main() {
    WordFrequencyMenu menu;
    menu.displayMenu();
    return 0;
}
