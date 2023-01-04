/*
    Author: Nyktor
    Date: 15th from Yule 12,023 HE - 04/01/2023
    Description: Tic Tac Toe terminal game
*/

#include <stdio.h>

//function prototypes
void printBoard();
void resetBoard();

//var & const declaration
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
#define x 3
#define y 3

char board[x][y];

//main function
int main(){

    resetBoard();
    printBoard();

    return 0;
}

void resetBoard(){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){

            board[i][j] = ' ';

        }
    }
}

void printBoard(){
    printf("  %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c", board[2][0], board[2][1], board[2][2]);
}
