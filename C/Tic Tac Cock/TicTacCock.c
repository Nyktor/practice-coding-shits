/*
    Author: Nyktor
    Date: 15th from Yule 12,023 HE - 04/01/2023
    Description: Tic Tac Toe terminal game
*/

#include <stdio.h>

//function prototypes
void printBoard();
void resetBoard();
void selectSquare(char);
int emptySquares();
char getWinner();

//var & const declaration
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
#define rows 3
#define cols 3
char board[rows][cols];



//main function
int main(){

    resetBoard();
    printBoard();
    while(emptySquares() != 0){
        selectSquare(PLAYER1);
        selectSquare(PLAYER2);
    }

    if(getWinner() == ' '){
        printf("\nIt's a tie!");
    }else{
        printf("\nPlayer %c wins!", getWinner());
    }

    return 0;
}

//functions and actions
void resetBoard(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

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

void selectSquare(char player){
    int x, y;
    printf("\nPlayer %c's turn!", player);
    do{
    printf("\nSelect a row number (1-3): ");
    scanf("%d", &x);
    x--;

    printf("\nSelect a column number (1-3): ");
    scanf("%d", &y);
    y--;

    if(x >-1 && x < 3 && y > -1 && y < 3){
        if(board[x][y] == ' '){
            board[x][y] = player;
        }else{
            printf("\n That square is already taken!");
        }
    }else{
        printf("\n That's not a valid square!");
    }

    }while(x >-1 && x < 3 && y > -1 && y < 3 && board[x][y] == ' ');
   
}

int emptySquares(){
    int empty = 9;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == ' '){
                empty--;
            }
        }
    }

    return empty;
}

char getWinner(){
    //check rows
    for(int i = 0; i < rows; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    //check columns
    for(int i = 0; i < rows; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    //check diagonals
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            return board[0][0];
        }else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return board[0][2];
        }

    //it's a draw
    return ' ';
}