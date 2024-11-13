/*
    Jakobe Lahr
    Computer Science FA_24
    Due: 11/12/24
    Lab 5: Lab 5 is a number guessing game. The game itself picks a random 
    number from 1 - 100 and then allows you 20 chances to guess the number 
    with a high or low to tell you which direction to guess next. The game 
    also has over 10 different messages for each winning, losing, and 
    replaying the game. It also has an incorpertated function to track the 
    amount of loses and wins you get in a session of playing. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class RandomNumGame {
private:
    int wins = 0;
    int losses = 0;
    const int maxAttempts = 20;
    int numberToGuess;

    std::vector<std::string> winM = {             //Messages for win
        "You guessed it!", "Well done!",
        "Victory is yours!", "Youre a genius!", "You won!",
        "Impressive! You've won!", "You got it!", "That's correct!",
        "Amazing guess! You win!", "You guessed correctly!"
    };

    std::vector<std::string> loseM = {          //Messages for losing
        "Better luck next time!", "Close, but not quite!", "Almost there, but you lost.",
        "You'll get it next time!", "It wasn't your day.", "You didn't guess it.",
        "You did not guess correctly.", "Keep trying, you'll get it!",
        "Close, but no cigar!", "Don't worry, try again!"
    };

    std::vector<std::string> replayM = {        //Messages for trying again
        "Want to play again? (y/n): ", "Care for another round? (y/n): ",
        "Up for another try? (y/n): ", "Would you like another game? (y/n): ",
        "Try your luck again? (y/n): ", "Shall we go again? (y/n): ",
        "One more round? (y/n): ", "Fancy another game? (y/n): ",
        "Think you can win this time? (y/n): ", "Another chance? (y/n): "
    };

    void genRN() {
        numberToGuess = rand() % 101; // Random number between 0 and 100
    }

    void displayM(const std::vector<std::string>& messages) {
        int index = rand() % 10;
        std::cout << messages[index] << std::endl;
    }

    void play1Game() {
        genRN();
        int attempts = 0;
        bool won = false;

        std::cout << "There is a number between 0 and 100. Try to guess it!\n";

        while (attempts < maxAttempts) {
            int guess;
            std::cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ": ";
            std::cin >> guess;

            if (guess == numberToGuess) {
                displayM(winM);
                wins++;
                won = true;
                break;
            }
            else if (guess < numberToGuess) {
                std::cout << "Too low. Try again.\n";
            }
            else {
                std::cout << "Too high. Try again.\n";
            }
            attempts++;
        }

        if (!won) {
            displayM(loseM);
            losses++;
        }
    }

public:
    RandomNumGame() {
        srand(time(NULL)); //time seed
    }

    void playGame() {
        char choice;
        do {
            play1Game();
            displayM(replayM);
            std::cin >> choice;
        } while (choice == 'y');

        displayResults();
    }

    void displayResults() {                //Final output
        std::cout << "\nGame over. Total Wins: " << wins << " | Total Losses: " << losses << std::endl;
    }
};

int main() {
    RandomNumGame game;
    game.playGame();
    return 0;
}
