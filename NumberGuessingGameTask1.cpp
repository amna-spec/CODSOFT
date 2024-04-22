#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seeding the random number, generator
		srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100."<<endl<<endl;

    // Main game loop
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " correctly!\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    } while (guess != secretNumber);

    return 0;
}

