/*
    Author: Nyktor
    Date: Sungaia, 25 from Yule of 12023 HE
    Description: A small quiz program
    File: main file
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Elementarium.h"

/* Using SPECIFIC std libraries, it is bad practice to use the whole std*/
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;

/* Global variables */
fstream elemenfile;

/* Function prototypes*/
void readFile();
void addElementarium();

/* Main function */
int main(){

    unsigned short option;
    bool valid = false;

    cout << "********************" << endl;
    cout << "Welcome to Aetheria!" << endl;
    cout << "*********************" << endl;

    do{

        cout << "\nWhat do you wish to do?" << endl;
        cout << "1. Add an Elementarium" << endl;
        cout << "2. See current Elementariums" << endl;
        cout << "3. Exit\n" << endl;

        cout << "Select number: ";
        fflush(stdin);
        cin >> option;

        switch(option){
            case 1:
                addElementarium();
                break;
            case 2:
                readFile();
                break;
            case 3:
                cout << "See you soon!" << endl;
                return 0;
            default:
                cout << "That's not a valid number!" << endl;
                break;
        }

    }while(!valid);

    return 0;
}

void readFile(){
    elemenfile.open("Elementariums.csv", std::ios::in);
    if(!elemenfile){
        cout << "There's something wrong with da file" << endl;
        return;
    }else{
        while(!elemenfile.eof()){
            /*Print the elementarium's data*/
            string name, element, aether, values;
            getline(elemenfile, name, ',');
            cout << "\nElementarium: " << name << endl;
            getline(elemenfile, element, ',');
            cout << "   Elemental affinity:  " << element << endl;
            getline(elemenfile, aether, ',');
            cout << "   Aetherical affinity: " << aether << endl;
            getline(elemenfile, values);
        }
        string dummyvar;
        cout << "\nType literally anything to continue: ";
        cin >> dummyvar;
        fflush(stdin);
        elemenfile.close();
    }
}

void addElementarium(){
    string line = "\n", scoresString = "", name;
    score scores[10], affinity;

    //Open da fileee
    elemenfile.open("Elementariums.csv", std::ios::app);
    if(!elemenfile){
        cout << "There's something wrong with da file" << endl;
        return;
    }

    cout << "* ADDING A NEW ELEMENTARIUM *" << endl;

    //Get name and put it first
    cout << "What's their name?: ";
    cin >> name;
    line.append(name).append(",");

    //Store the scores in the array
    cout << "\nWhat are their elemental scores?: " << endl;
    for(int i = 0; i < 10; i++){
        cout << getElementStringByID(i) << ": ";
        cin >> affinity;
        scores[i] = affinity;
        scoresString.append(std::to_string(affinity).append(","));
    }

    //Creates the new Elementarium object
    Affinities aff(scores);
    Elementarium ele(name, aff);
    eElement element = aff.getKinElement();
    eAether aether = aff.getKinAether().getEnum();

    line.append(getElementStringByID(element).append(","));
    line.append(getAetherStringByID(aether)).append(",");
    line.append(scoresString);
    cout << "\n* NEW ELEMENTARIUM SUCCESFULLY ADDED! *" << endl;
}