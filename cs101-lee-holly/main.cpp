#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string myString;
int x_value;
string char_value;
int y_value;

int main() {
    ifstream inputFile("/Users/leeholly/CS101/cs101-lee-holly/cs101-lee-holly/inputData.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading.\n";
    }
    while (getline(inputFile, myString)) {
        stringstream inputLine(myString);
        inputLine >> x_value;
        inputLine >> char_value;
        inputLine >> y_value;
        cout << x_value << " " << char_value << " " << y_value << endl;
        
        
    }
}

