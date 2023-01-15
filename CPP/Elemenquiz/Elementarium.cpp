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

//Five aethers:
Aether Flowing(HYDROS, VITAS);
Aether Unbreakable(TERRA, METALLUM);
Aether Howling(VENTUS, GLAKIES);
Aether Polar(LUX, NYX);

//Elementarium constructor
Elementarium::Elementarium(string iName, Element iElement, Aether iAffinity){
    name = iName;
    eAffinity = iElement;
    aAffinity = iAffinity;
};
//Elementarium set name
void Elementarium::setName(string iName){
    name = iName;
};