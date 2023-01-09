/*
    Author: Nyktor
    Date: Vengaia, 18 of Yule of 12023 HE
    Description: turn based, simple PVP, for practicing structs
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


/* Constants */
#define NAME_MAX_LENGTH 12
#define MINHP 0
#define MAXHP 30
#define MINDMG 3
#define MAXDMG 10

/* User-defined types*/
typedef struct {
    int id;
    char name[NAME_MAX_LENGTH];
    int hp;
    int dmg;
    bool isAlive;
} Player;

/* Global variables */
int round;
int currentPlayerId;
Player player1;
Player player2;

/* Function prototypes */
void resetGame();
void selectNames();
void printHP();
void startTurn();
int checkWinner();


/*---------------------------------------------------------------------------------------*/
//Main func
int main(){

    char playAgain = 'N'; 

    do{
        resetGame();
        selectNames();

        while(checkWinner() == 0){
            printHP();
            startTurn();

        }

        printf("\nDo you want to play again? (Y/N): ");
        scanf("%c", &playAgain);
        playAgain = toupper(playAgain);

    }while(playAgain == 'Y');

        printf("\nThank you for playing <3\n");

    return 0;
}

/* Reset all parameters of the game */
void resetGame(){
    round = 0;
    //Resets players' stats
    strncpy(player1.name, "", NAME_MAX_LENGTH);
    strncpy(player2.name, "", NAME_MAX_LENGTH);
    player1.hp = MAXHP;
    player2.hp = MAXHP;
    player1.isAlive = true;
    player2.isAlive = true;
    currentPlayerId = 0;
}

/* Explains itself lol */
void selectNames(){
    printf("PLAYER 1: Select your name!");
    printf("\n(maximum 12 characters!)");
    printf("\nName: ");
    scanf("%s", &player1.name);

    printf("\nPLAYER 2: Select your name!");
    printf("\n(maximum 12 characters!)");
    printf("\nName: ");
    scanf("%s", &player2.name);

    printf("\n\n%s VS %s", player1.name, player2.name);
    printf("\nFIGHT!");
    while((getchar()) != '\n');
}

/* Method used to print both players' HP*/
void printHP(){
    //Player 1
    printf("\n%s [", player1.name);
    for(int i = 0; i < player1.hp / 5; i++){
        printf("||||| ");
    }
    for(int i = 0; i < player1.hp % 5; i++){
        printf("|");
    }
    printf("]");
    //Player 2
    printf("\n%s [", player2.name);
    for(int i = 0; i < player2.hp / 5; i++){
        printf("||||| ");
    }
    for(int i = 0; i < player2.hp % 5; i++){
        printf("|");
    }
    printf("]");
}

/* Method that is called each turn */
void startTurn(){
    if(currentPlayerId == 0){
        //IE: game at the start, chooses a random player
        srand(time(0));
        currentPlayerId = rand() % 2 + 1;
    }
}

/* Checks if there's a winner, returns its ID if is there one, returns 0 if not*/
int checkWinner(){
    if(!player1.isAlive){
        return 2;
    }else if(!player2.isAlive){
        return 1;
    }
    return 0;
}