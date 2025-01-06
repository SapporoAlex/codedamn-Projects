#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

std::vector<std::string> possibleMoves = {"rock", "scissors", "paper"};

int comChoice() {
    int choice;
    choice = std::rand() % 3;

    std::cout << "Computer chose " << possibleMoves[choice] << std::endl;
    return choice;
}


int main() {
std::srand(static_cast<unsigned>(std::time(nullptr)));
bool run = true;
while (run) {
    int playerChoice;
    int computerChoice;
    std::cout << "(1)Rock, (2)scissors or (3)paper? (0)Quit" << std::endl;
    std::cin >> playerChoice;
    playerChoice -= 1;
    if (playerChoice == -1) {
        std::cout << "Thanks for playing.\n";
        run = false;
        break;
    }
    else if (playerChoice < -1 || playerChoice > 2) {
        std::cout << "Invalid selection.\n";
    }
    if (playerChoice > -1 && playerChoice < 3) {
        std::cout << "You chose " << possibleMoves[playerChoice] << std::endl;
        computerChoice = comChoice();
        if (playerChoice == (computerChoice + 1) % 3) {
            std::cout << possibleMoves[computerChoice] << " beats " << possibleMoves[playerChoice] << std::endl;
            std::cout << "Computer wins!\n";
        }
        else if (computerChoice == (playerChoice + 1) % 3) {
            std::cout << possibleMoves[playerChoice] << " beats " << possibleMoves[computerChoice] << std::endl;
            std::cout << "Player wins!\n";
        }
        else {
            std::cout << "Draw.\n";
        }
    }
}
    return 0;
}
