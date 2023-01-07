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
    bool alive;
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
bool isDead(Player);

//Main func
int main(){

    resetGame();

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
    player1.alive = true;
    player2.alive = true;
    currentPlayerId = 0;
    //Recalls selectNames method
    selectNames();
}

/* Explains itself lol */
void selectNames(){
    printf("\nPLAYER 1: Select your name!");
    printf("\n(maximum 12 characters!)");
    printf("\nName: ");
    scanf("%s", &player1.name);

    printf("\nPLAYER 2: Select your name!");
    printf("\n(maximum 12 characters!)");
    printf("\nName: ");
    scanf("%s", &player2.name);

    printf("\n\n%s VS %s", player1.name, player2.name);
    printf("\nFIGHT!");
}

/* Method that is called each turn */
void startTurn(){
    if(currentPlayerId == 0){

    }
}

/* Checks if the passed player is ded*/
bool isDead(Player player){
    return !player.alive;
}

/* Checks if there's a winner, returns its ID if is there one, returns 0 if not*/
int checkWinner(){
    if(isDead(player1)){
        return 2;
    }else if(isDead(player2)){
        return 1;
    }
    return 0;
}