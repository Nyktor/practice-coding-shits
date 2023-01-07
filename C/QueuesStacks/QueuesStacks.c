/*
    Author: Nyktor
    Date: 17 de Yule de 12023
    Description: practice stacks and queues
*/

#include <stdio.h>
#include <stdbool.h>

//Stacks methods(First In Last Out)
void push(int[], int);
void pop(int[]);

//Queue methods(First In First Out)
void enqueue(int[], int);
void dequeue(int[]);

//Other methods
bool isEmpty(int[]);

//Global variables & constants
#define size 8
int list[size];


//Main function: ASSUME AN ARRAY WITH A MAX SIZE OF 8 ITEMS
int main(){

    //print the whole array
    for (int i = 1; i <= size; i++){
        push(list, i);
    }
    dequeue(list);
    pop(list);
    push(list, 1);
    for(int i = 0; i < size; i++){
        printf("%d\n", list[i]);
    }

    return 0;
}


//Boolean, return if the list is empty - FINISHED
bool isEmpty(int list[]){
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

/* STACK METHODS  - FINISHED*/
void push(int list[], int number){
    //If the list is empty, put the first item as the selected number
    if(isEmpty(list)){
        list[0] = number;
        return;
    }
    //If it's not empty...
    for(int i = size-1; i >= 0; i--){
        //Check if it's full if the last item is not 0
        if(i == size-1 && list[i] != 0){
            printf("\nError: Array's full!\n");
            return;
        //If it's not full, check backwards until we find a number different than 0
        }else if(list[i] != 0){
            list[i+1] = number;
            return;
        }
    }
    
}

void pop(int list[]){
    //If the list is empty we can pop no shit
    if(isEmpty(list)){
            printf("\nError: Array's empty!\n");
        return;
    }
    //If it's not empty...
    for(int i = size-1; i >= 0; i--){
        //Check item by item backwards until one is NOT zero, then make it zero
        if(list[i] != 0){
            list[i] = 0;
            return;
        }
    }
    
}


/* QUEUE METHODS - FINISHED*/
void enqueue(int list[], int number){
    push(list, number); //it does the fucking same so doesn't matter
}

void dequeue(int list[]){
    //fuck off if it's empty
    if(isEmpty(list)){
        return;
    }else{
        //if not, delete the first number
        list[0] = 0;
        //and swap the two consecutive numbers til the end
        for(int i = 0; i < size-1; i++){
            int temp;
            temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp;
        }
    }
}