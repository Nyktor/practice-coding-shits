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
char board[3][3];



//main function
int main(){

    char winner = ' ';
    char answer = 'Y';

    do{
        resetBoard();
        while(winner == ' ' && emptySquares() != 0){
            printBoard();
            selectSquare(PLAYER1);
            winner = getWinner();

            if(getWinner() != ' ' || emptySquares() == 0){
                break;
            }

            printBoard();
            selectSquare(PLAYER2);
            winner = getWinner();

            if(getWinner() != ' ' || emptySquares() == 0){
                break;
            }
        }
        
        if(winner == ' '){
            printf("\n It's a tie!");
        }else{
            printf("Player %c is the winner!", winner);
        }
        printf("\nWould you like to play again? (Y/N): ");
        scanf("%c", &answer);

    }while(answer == 'Y');

    return 0;
}

//functions and actions
void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            board[i][j] = ' ';

        }
    }
}

void printBoard(){
    printf("\n  %c | %c | %c", board[0][0], board[0][1], board[0][2]);
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

        printf("Select a column number (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] == ' '){
            board[x][y] = player;
            break;
        }else{
            printf("\n That square is already taken!");
        }

    }while(board[x][y] == ' ');
   
}

int emptySquares(){
    int empty = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                empty--;
            }
        }
    }
    return empty;
}

char getWinner(){
    //check rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }

    //check columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }

    //it's a draw
    return ' ';
}