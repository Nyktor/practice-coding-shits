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
} Player;

/* Global variables */
int roundNumber;
int currentPlayerId;
Player player1;
Player player2;

/* Function prototypes */
void resetGame();
void selectNames();
void printHP();
void startTurn();
void attack(int);
Player getPlayer(int);
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
        printf("\n\n*********************************");
        printf("\n%s WINS!! uwu", getPlayer(checkWinner()).name);
        printf("\n*********************************");

        printf("\nDo you want to play again? (Y/N): ");
        scanf("%c", &playAgain);
        playAgain = toupper(playAgain);

    }while(playAgain == 'Y');

        printf("\nThank you for playing <3\n");

    return 0;
}

/* Reset all parameters of the game */
void resetGame(){
    roundNumber = 0;
    //Resets players' stats
    strncpy(player1.name, "", NAME_MAX_LENGTH);
    strncpy(player2.name, "", NAME_MAX_LENGTH);
    player1.hp = MAXHP;
    player2.hp = MAXHP;
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
    printf("\n\n%s [", player1.name);
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
    char action;
    if(currentPlayerId == 0){
        //IE: game at the start, chooses a random player
        srand(time(0));
        currentPlayerId = rand() % 2 + 1;
    }
    printf("\n\nYour turn, %s!", getPlayer(currentPlayerId).name);
    printf("\nWhat do you want to do?");
    printf(" \nAttack: \"A\"");
    printf("\nChoose: ");
    scanf("%c", &action);
    scanf("%c");
    action = toupper(action);

    if(action == 'A'){
        //Attacks the other player and changes the current player ID
        attack(currentPlayerId % 2 + 1);
        currentPlayerId = currentPlayerId % 2 + 1;
    }
}

/* Checks if there's a winner, returns its ID if is there one, returns 0 if not*/
int checkWinner(){
    if(player1.hp <= 0){
        return 2;
    }else if(player2.hp <= 0){
        return 1;
    }
    return 0;
}

/* Substracts a random amount of HP from the selected character*/
void attack(int id){
    srand(time(0));
    if(id == 1){
        player1.hp -= ((rand() % (MAXDMG - MINDMG + 1)) + MINDMG);
    }else if (id == 2){
        player2.hp -= ((rand() % (MAXDMG - MINDMG + 1)) + MINDMG);
    }
}

/* Gets player by ID */
Player getPlayer(int id){
    if(id == 1){
        return player1;
    }else if(id == 2){
        return player2;
    }
}