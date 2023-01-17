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
    affinity1 = elemNULL;
    affinity2 = elemNULL;
    e = aethNULL;
}
Aether::Aether(eElement e1, eElement e2, eAether ae){
    affinity1 = e1;
    affinity2 = e2;
    e = ae;
};

/* Five Aether objects*/
Aether Striking(IGNIS, ELEKTRO, STRIKING);
Aether Flowing(HYDROS, VITAS, FLOWING);
Aether Unbreakable(TERRA, METALLUM, UNBREAKABLE);
Aether Howling(VENTUS, GLAKIES, HOWLING);
Aether Polar(LUX, NYX, POLAR);

//Affinities constructor
Affinities::Affinities(){
    for(int i = 0; i < 10; i++){
        AllElements[i] = 0;
    }
}
Affinities::Affinities(score scores[10]){
    for(int i = 0; i < 10; i++){
        AllElements[i] = scores[i];
    }
}

//Elementarium constructor
Elementarium::Elementarium(string iName, Affinities iAff){
    name = iName;
    aff = iAff;
};

//Elementarium set name
void Elementarium::setName(string iName){
    name = iName;
};

//Returns the highest elemental affinity
eElement Elementarium::getElementalAffinity(){
    eElement e;
    score highest = 0;
    score* pAllElements = aff.getAllElements();
    for(int i = 0; i < 10; i++){
        if(pAllElements[i] > highest){
            highest = pAllElements[i];
            e = eElement(i);
        }
    }
    return e;
}

//Returns the highest aetherical affinity (Aether class)
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

//Pointer to an array with all aetherical scores
score* Affinities::getAllAethers(){
    static score allAethers[5];
    
        allAethers[0] = getStrikingAffinity();
        allAethers[1] = getFlowingAffinity();
        allAethers[2] = getUnbreakableAffinity();
        allAethers[3] = getHowlingAffinity();
        allAethers[4] = getPolarAffinity();
    
    return allAethers;
}

//Pointer to an array with all elemental scores
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
