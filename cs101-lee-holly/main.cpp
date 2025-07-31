#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string myString;
int x_value;
int max_x = 0;
int max_y = 0;
string char_value;
int y_value;
struct Pixel {
    int x;
    int y;
    string block;
};

int main() {
    ifstream inputFile("/Users/leeholly/CS101/cs101-lee-holly/cs101-lee-holly/inputData.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading.\n";
    }
    vector<Pixel> pixels;
    Pixel p;
    while (getline(inputFile, myString)) {
        stringstream inputLine(myString);
        inputLine >> x_value;
        if (x_value > max_x) {
            max_x = x_value;
        }
        inputLine >> char_value;
        inputLine >> y_value;
        if (y_value > max_y) {
            max_y = y_value;
        }
        p.x = x_value;
        p.y = y_value;
        p.block = char_value;
        pixels.push_back(p);
    }
    
    vector<vector<string>> grid(max_y+1, vector<string>(max_x +1, " "));
    for (const Pixel& p : pixels) {
        grid[p.y][p.x] = p.block;
    }
    for (int i=0; i <= max_y; ++i) {
        for (int j=0; j <= max_x; ++j){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

