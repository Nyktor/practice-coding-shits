/*
    Author: Nyktor
    Date: Mergaia, 26 from Yule of 12023HE
    Description: Elementarium things classes
    File: source file
*/
#include <iostream>
#include <string>
#include "Elementarium.h"

/* Using stuff */
using std::string;

/* Elementarium functions */

//Aether constructors
Aether::Aether(){
    affinity1 = IGNIS;
    affinity2 = IGNIS;
}
Aether::Aether(Element e1, Element e2){
    affinity1 = e1;
    affinity2 = e2;
};

//Elementarium constructor
Elementarium::Elementarium(string iName, Affinities iAff){
    name = iName;
    aff = iAff;
};

//Elementarium set name
void Elementarium::setName(string iName){
    name = iName;
};

//Elementarium get elemental affinity
Element Elementarium::getElementalAffinity(){
    Element e;
    score highest = 0;
    score* pAllElements = aff.getAllElements();
    for(int i = 0; i < 10; i++){
        if(pAllElements[i] > highest){
            highest = pAllElements[i];
            e = Element(i);
        }
    }
    return e;
}

//Returns the highest aetherical affinity
Aether Elementarium::getAethericalAffinity(){
    Aether ae;
    score highest = 0;
    score* pAllAethers = aff.getAllAethers();
    int highestId = -1;
    for(int i = 0; i < 5; i++){
        if(pAllAethers[i] > highest){
            highest = pAllAethers[i];
            highestId = i;
        }
    }

    switch(highestId){
        case 0:
            return Striking;
        case 1:
            return Flowing;
        case 2:
            return Unbreakable;
        case 3:
            return Howling;
        case 4:
            return Polar;
        default:
            return ae;            
    }
}

//Elementarium get all aetherical affinities in array
score* Affinities::getAllAethers(){
    static score allAethers[5];
    
        allAethers[0] = getStrikingAffinity();
        allAethers[1] = getFlowingAffinity();
        allAethers[2] = getUnbreakableAffinity();
        allAethers[3] = getHowlingAffinity();
        allAethers[4] = getPolarAffinity();
    
    return allAethers;
}

//Elementarium get all elemental affinities in array
score* Affinities::getAllElements(){
    static score allElements[10];
    
        allElements[0] = Ignis;
        allElements[1] = Elektro;
        allElements[2] = Hydros;
        allElements[3] = Vitas;
        allElements[4] = Terra;
        allElements[5] = Metallum;
        allElements[6] = Ventus;
        allElements[7] = Glakies;
        allElements[8] = Lux;
        allElements[9] = Nyx;
    
    return allElements;
}
