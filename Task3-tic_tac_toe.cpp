#include<bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

void displayBoard(){
    cout << endl;
    for(int i=0; i<3; i++){
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if(i < 2) cout << "-----------" << endl;
    }
    cout << endl;
}

bool checkWin(char player){
    for(int i=0; i<3; i++)
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
    for(int i=0; i<3; i++)
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;
    return false;
}

bool checkDraw(){
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
    return true;
}

void resetBoard(){
    char num = '1';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = num++;
}

int main(){
    char playAgain;

    do {
        resetBoard();
        char currentPlayer = 'X';
        int move;
        bool gameOver = false;

        cout << "TIC-TAC-TOE GAME" << endl;
        cout << "Player 1: X  |  Player 2: O" << endl;

        while(!gameOver){
            displayBoard();

            cout << "Player " << currentPlayer << " enter your move (1-9): ";
            cin >> move;

            if(move < 1 || move > 9){
                cout << "Invalid move! Enter a number between 1-9." << endl;
                continue;
            }

            int row = (move-1) / 3;
            int col = (move-1) % 3;

            if(board[row][col] == 'X' || board[row][col] == 'O'){
                cout << "Cell already taken! Choose another." << endl;
                continue;
            }

            board[row][col] = currentPlayer;

            if(checkWin(currentPlayer)){
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameOver = true;
            }
            else if(checkDraw()){
                displayBoard();
                cout << "It's a Draw! Well played both!" << endl;
                gameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}