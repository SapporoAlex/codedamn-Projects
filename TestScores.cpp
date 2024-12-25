#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>


int main() {
    std::ifstream inputFile("scores.txt");
    if (!inputFile) {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    } else {

    std::vector<std::pair<int, std::string>> scores;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string firstName, lastName;
        int score;


        // Extract first name, last name, and score from the line
        if (lineStream >> firstName >> lastName >> score) {
            std::string fullName = firstName + " " + lastName;
            scores.push_back({score, fullName});
        } else {
            std::cerr << "Error: Malformed line: " << line << std::endl;
        }
    }

    inputFile.close();

    std::sort(scores.begin(), scores.end(), [](const auto &a, const auto &b) {
        return a.first > b.first; // Compare scores (first element of the pair)
    });
        // Output the top 3 scores (or fewer if less than 3 entries)
    int numToDisplay = std::min(3, static_cast<int>(scores.size()));
    if (numToDisplay > 0) {
        std::cout << "Top " << numToDisplay << " highest scores:" << std::endl;
        for (int i = 0; i < numToDisplay; ++i) {
            std::cout << scores[i].second << " with a score of " << scores[i].first << std::endl;
        }
    } else {
        std::cout << "No valid data found in the file." << std::endl;
    }
    }
    return 0;
    }