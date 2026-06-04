#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    char playagain;

    cout << "NUMBER GUESSING GAME" << endl;

    do {
        int secretnum = rand() % 100 + 1;
        int guess;
        int attempts = 0;  

        cout << "Yeah! You're trying to guess a number between 1 to 100" << endl;
        cout << "Let's Go!" << endl;

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if(guess < 1 || guess > 100){
                cout << "Try to use numbers between 1 to 100..." << endl;
            }
            else if(guess < secretnum){
                cout << "Too Low!" << endl;
            }
            else if(guess > secretnum){
                cout << "Too High!" << endl;
            }
            else {
                cout << "Great! You made it! The Number is " << secretnum << endl;
                cout << "You've guessed in " << attempts << " attempts" << endl;

                if(attempts <= 3){
                    cout << "You're a fast player!" << endl;
                } else if(attempts <= 7){
                    cout << "Good job!" << endl;
                } else {
                    cout << "Keep practicing!" << endl;
                }
            }

        } while(guess != secretnum);  // fix: moved here

        cout << "Do you want to play again? (Y/N): ";
        cin >> playagain;  

    } while(playagain == 'y' || playagain == 'Y');

    cout << "Thanks for playing." << endl;

    return 0;  
}