#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Intro {
public:
    string name;

    Intro() {
        cout << "Enter your name (Player): ";
        cin >> name;
        cout << "\n\t\tWELCOME [" << name << "] TO THE GAME: ROCK, PAPER, SCISSOR!" << endl;
        cout << "\t\t\n1. ROCK\n2. PAPER\n3. SCISSOR\n" << endl;
    }
};

class InputChoice : public Intro {
public:
    int roundNumber, playerChoice, computerChoice, playerScore = 0, computerScore = 0;

    void takeData() {
        srand(time(0));

        for (roundNumber = 1; roundNumber <= 3; roundNumber++) {

            cout << "\nEnter your choice for round " << roundNumber << " (1 for ROCK, 2 for PAPER, 3 for SCISSOR): ";
            cin >> playerChoice;

            computerChoice = rand() % 3 + 1;
            cout << "Computer's choice for round " << roundNumber << " is: " << computerChoice << endl;

            if (playerChoice < 1 || playerChoice > 3) {
                cout << "\t\tInvalid Choice. Please enter a valid number (1, 2, or 3).\n";
                break;
            }

            if (playerChoice == computerChoice) {
                playerScore++;
                computerScore++;
            } else if ((playerChoice == 1 && computerChoice == 3) || 
                       (playerChoice == 2 && computerChoice == 1) || 
                       (playerChoice == 3 && computerChoice == 2)) {
                playerScore++;
            } else {
                computerScore++;
            }
        }
    }
};

class Result : public InputChoice {
public:
    
    void displayResult() {
        takeData();  

        cout << "\n\n\t\tRESULTS:" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Player Score: " << playerScore << endl;
        cout << "Computer Score: " << computerScore << endl;

       
        if (playerScore == computerScore) {
            cout << "\t\tIt's a Tie!\n\n" << endl;
        } else if (playerScore > computerScore) {
            cout << "\t\tCongratulations, " << name << "! You Won!\n\n" << endl;
        } else {
            cout << "\t\tComputer Won! Better luck next time!\n\n"<< endl;
        }
    }
};

int main() {
    Result game;
    game.displayResult();

    return 0;
}
