#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr)); // Seed for random number generation
    const int maxTries = 5; // Maximum number of attempts
    int secretNumber = rand() % 50 + 1; // Generating a random number between 1 and 50
    int guess;
    int tries = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 50. Can you guess it?\n";

    while (tries < maxTries) {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed it right in " << tries << " tries!\n";
            break;
        }
        else if (guess < secretNumber) {
            cout << "Try a higher number.\n";
        }
        else {
            cout << "Try a lower number.\n";
        }
    }

    if (tries == maxTries) {
        cout << "Sorry, you've used all your attempts. The number I was thinking of was " << secretNumber << ".\n";
    }

    return 0;
}