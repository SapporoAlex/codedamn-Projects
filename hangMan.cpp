#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void displayWord(const std::string& word, const std::string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) != std::string::npos) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << "\n";
}

bool isWordGuessed(const std::string& word, const std::string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void playHangman() {
    // List of words
    const std::vector<std::string> wordList = {"programming", "hangman", "computer", "keyboard", "mouse"};
    
    // Select a random word
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::string selectedWord = wordList[std::rand() % wordList.size()];
    
    std::string guessedLetters = "";
    int maxAttempts = 6;
    int wrongGuesses = 0;

    std::cout << "Welcome to Hangman!\n";

    while (wrongGuesses < maxAttempts) {
        std::cout << "\nWord: ";
        displayWord(selectedWord, guessedLetters);

        std::cout << "Guessed letters: " << guessedLetters << "\n";
        std::cout << "Remaining attempts: " << (maxAttempts - wrongGuesses) << "\n";
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;

        // Check if the letter has already been guessed
        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter.\n";
            continue;
        }

        // Add guess to guessed letters
        guessedLetters += guess;

        // Check if the guess is correct
        if (selectedWord.find(guess) != std::string::npos) {
            std::cout << "Correct guess!\n";
        } else {
            std::cout << "Wrong guess!\n";
            wrongGuesses++;
        }

        // Check if the word has been completely guessed
        if (isWordGuessed(selectedWord, guessedLetters)) {
            std::cout << "\nCongratulations! You guessed the word: " << selectedWord << "\n";
            return;
        }
    }

    // If the user runs out of attempts
    std::cout << "\nGame over! The correct word was: " << selectedWord << "\n";
}

int main() {
    playHangman();
    return 0;
}
