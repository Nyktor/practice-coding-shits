/* 
	Author: Nyktor
	Date: Mergaia, 26 from Yule of 12023 HE
	File: header file
	Description: it's a header :0
*/

#include <iostream>
#include <string>

/*User defined datatypes*/
enum eElement{IGNIS, ELEKTRO, HYDROS, VITAS, TERRA, METALLUM, VENTUS, GLAKIES, LUX, NYX};
enum eAether{STRIKING, FLOWING, UNBREAKABLE, HOWLING, POLAR};

typedef unsigned short score;
typedef unsigned short ID;

/*Y'know, I be using things*/
using std::string;

/* Useful functions */
string aetherNames[5] = {"STRIKING", "FLOWING", "UNBREAKABLE", "HOWLING", "POLAR"};
string elementNames[10] = { "IGNIS", "ELEKTRO", "HYDROS", "VITAS", "TERRA", "METALLUM", "VENTUS", "GLAKIES", "LUX", "NYX"};

string getElementStringByID(ID id){return elementNames[id];}
string getAetherStringByID(ID id){return aetherNames[id];}

/*Classes interfaces*/
class Aether{
	private:
		eAether e;
		eElement affinity1;
		eElement affinity2;
		unsigned short concentration;
	public:
		Aether();
		Aether(eElement, eElement, eAether);
		string getName(){return getAetherStringByID(e);}
		unsigned short getConcentration(){return concentration;}
};


/* Class for ALL affinities, elemental AND aetherical*/
class Affinities{
	public:
		score Ignis, Elektro, Hydros, Vitas, Terra, 
			  Metallum, Ventus, Glakies, Lux, Nyx;
	private:
		score striking = Ignis + Elektro, 
			  flowing = Hydros + Vitas,
			  unbreakable = Terra + Metallum,
			  howling = Ventus + Glakies,
			  polar = Lux + Nyx;

		score AllElements[10]={Ignis, Elektro, Hydros,
							   Vitas, Terra, Metallum,
							   Ventus, Glakies, Lux, Nyx};
	public:
		score getStrikingAffinity(){return striking;}
		score getFlowingAffinity(){return flowing;}
		score getUnbreakableAffinity(){return unbreakable;}
		score getHowlingAffinity(){return howling;}
		score getPolarAffinity(){return polar;}
		score* getAllElements(); //ptr to an array with all elemental affinities
		score* getAllAethers(); //ptr to an array with all aether affinities
};

/* Class for an Elementarium*/
class Elementarium{
	private:
		string name;
		Affinities aff;
	public:
		Elementarium(string, Affinities aff);

		void setName(string);
		string getName(){return name;}
		eElement getElementalAffinity();
		Aether getAethericalAffinity();
};

