/*
    Author: Nyktor
    Date: 17 de Yule de 12023
    Description: practice stacks and queues
*/

#include <stdio.h>
#include <stdbool.h>

//Stacks (First In Last Out)
void push(int[], int, int);
void pop(int[], int);

//Queue (First In First Out)
void enqueue(int[], int, int);
void dequeue(int[], int);

bool isEmpty(int[], int);


//Main function
int main(){

    int list[3] = {
        1
    };
    int size = sizeof(list)/sizeof(list[0]);

    //print the whole array
    push(list, size, 4);
    for(int i = 0; i < size; i++){
        printf("%d\n", list[i]);
    }

    return 0;
}


//Boolean, return if the list is empty
bool isEmpty(int list[], int size){
    if(size == 0){ 
        return true;
        }

    for(int i = 0; i < size; i++){
        if(list[i] != 0){
            return false;
        }
    }

    return true;

}

/* STACK METHODS */
void push(int list[], int size, int number){
    int newArray[size+1];
    for(int i = 0; i < size; i++){
        newArray[i] = list[i];
    }
    newArray[size] = number;
}

void pop(int list[], int size){
    
}

/* QUEUE METHODS */
void enqueue(int list[], int size, int number){
    
}

void dequeue(int list[], int size){
    
}