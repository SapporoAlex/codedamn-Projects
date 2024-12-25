#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Function to read lines from a file into a vector
void readFile(ifstream &file, vector<string> &data) {
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line); // Add each line to the vector
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

// Function to write lines from a vector to a file
void writeFile(ofstream &file, const vector<string> &data) {
    if (file.is_open()) {
        for (const string &line : data) {
            file << line << endl; // Write each line to the file
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

int main() {
    vector<string> data; // Use a vector to store multiple lines

    ifstream ifile("source.txt"); // Input file stream
    ofstream ofile("dest.txt");   // Output file stream

    // Read from source file
    readFile(ifile, data);

    // Write to destination file
    writeFile(ofile, data);

    // Print the content of the vector to the console
    for (const string &line : data) {
        cout << line << endl;
    }
    

    return 0;
}