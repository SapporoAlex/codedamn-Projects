#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

int generateRandomNumber() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  return std::rand() % 100 + 1;
}

int main(){
  int randomNumber = generateRandomNumber();
  bool run = true;
  
  while (run) {
    int guess;
    std::cout << "Guess the number between 1 and 100\n";
    std::cin >> guess;
    if (guess > 100 | guess < 1) {
      std::cout << "I asked for a number between 1 and 100\n";
    }
    else if (guess + 10 > randomNumber & guess < randomNumber) {
      std::cout << "Just a little higher.\n";
    }
    else if (guess - 10 < randomNumber & guess > randomNumber) {
      std::cout << "Just a little lower.\n";
    }
    else if (guess < randomNumber) {
      std::cout << "Too low!\n";
    }
    else if (guess > randomNumber) {
      std::cout << "Too high!\n";
    }
    if (guess == randomNumber) {
      std::cout << "Well done!" << " It was " << std::to_string(randomNumber) << "\n";
      break;
    }
  }
  return 0;
}
