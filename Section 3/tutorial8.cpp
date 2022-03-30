#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));
    int secretNumber = rand() % 11;

    int guess;
    while (true) {
        cout << "Guess the secret number : ";
        cin >> guess;

        if (guess > secretNumber) cout << "Too big.\n";
        else if (guess < secretNumber) cout << "Too small.\n";
        else break;
    }

    printf("The secret number was %d and you guessed correctly %d.\n", secretNumber, guess);

    return 0;
}