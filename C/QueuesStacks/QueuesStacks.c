#include <stdio.h>
#include <stdbool.h>
/*
    Author: Nyktor
    Date: 17 de Yule de 12023
    Description: practice stacks and queues
*/

//Stacks (First In Last Out)
void push();
void pop();

//Queue (First In First Out)
void enqueue();
void dequeue();

bool isEmpty(int[]);


//Main function
int main(){

    int array[5];
    printf("%d", isEmpty(array));

    return 0;
}

//Boolean, return if the list is empty
bool isEmpty(int array[]){
    if(sizeOf(array) == 0) return true;

    for(int i = 0; i < sizeOf(array)/sizeOf(array[0]); i++){
        if(array[i] != 0){
            return false;
        }
    }

    return true;

}

/* STACK METHODS */
void push(int array[], int number){
    int size = sizeOf(array)/sizeOf(array[0]);
    int newArray[0];
}

void pop(){
    
}

/* QUEUE METHODS */
void enqueue(){
    
}

void dequeue(){
    
}