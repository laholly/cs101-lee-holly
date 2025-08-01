/*
    ----------------------------------------------------------------------------
    Program Title:    Reconstruct Hidden Message from Grid-Based Input
    Author:           Lee Holly
    Due Date:         August 3, 2025
    Course:           CSCI101 - Computer Science I
    Assignment:       8A: Final Project

    Description:
    This program reads a structured input text file where each line contains
    three values: an x-coordinate, a character, and a y-coordinate.

    It stores each record in a block structure and determines the maximum x and y
    values to dynamically allocate a 2D grid. After all data is read, it maps the
    characters into the grid based on their coordinates, and prints the grid
    row by row, revealing a hidden block-letter message.
    ----------------------------------------------------------------------------
*/

// Include necessary libraries for file I/O, strings, and data structures
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Declare variables used during parsing and max value tracking
string myString;
int x_value;
int y_value;
int max_x = 0;
int max_y = 0;
string char_value;

// Define a struct to store each parsed data block
struct Block {
    int x;
    int y;
    string x_y_block;
};

// Function to return the maximum of two integer values
int findMax(int currentValue, int currentMax) {
    if (currentValue > currentMax) {
        return currentValue;
    }
    return currentMax;
}


int main() {
    // Attempt to open the input data file
    ifstream inputFile("/Users/leeholly/CS101/cs101-lee-holly/cs101-lee-holly/inputData.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading.\n";
    }
    
    // Vector to store all parsed Block objects
    vector<Block> blocks;
    Block b;
    
    // Read each line from the input file and parse into x, y, char components
    while (getline(inputFile, myString)) {
        stringstream inputLine(myString);
        inputLine >> x_value;
        inputLine >> char_value;
        inputLine >> y_value;
        
        // Call findMax function to updated max_x and max_y as needed
        max_x = findMax(x_value, max_x);
        max_y = findMax(y_value, max_y);
        
        // Populate Block struct and store components in vector
        b.x = x_value;
        b.y = y_value;
        b.x_y_block = char_value;
        blocks.push_back(b);
    }
    
    // Create a 2D grid filled with spaces
    vector<vector<string>> grid(max_y+1, vector<string>(max_x +1, " "));
    
    // Place each character block in it appropriate (x, y) position
    for (const Block& b : blocks) {
        grid[b.y][b.x] = b.x_y_block;
    }
    
    // Print the grid row by row to reveal the hidden message
    for (int i=0; i <= max_y; ++i) {
        for (int j=0; j <= max_x; ++j){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
