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
int turn;
int currentPlayerId;
Player player1;
Player player2;

/* Function prototypes */
void resetGame();
void selectNames();
void startTurn();
int checkWinner();


/*---------------------------------------------------------------------------------------*/
//Main func
int main(){

    char playAgain; 

    do{
        resetGame();
        selectNames();

        printf("\nDo you want to play again? (Y/N): ");
        scanf("%c", &playAgain);
        playAgain = toupper(playAgain);

    }while(playAgain);


    return 0;
}

/* Reset all parameters of the game */
void resetGame(){
    turn = 0;
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

/* Method that is called each turn */
void startTurn(){
    if(currentPlayerId == 0){

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