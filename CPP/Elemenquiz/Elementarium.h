/* 
	Author: Nyktor
	Date: Mergaia, 26 from Yule of 12023 HE
	File: header file
	Description: it's a header :0
*/

#include <iostream>
#include <string>

/*User defined datatypes*/
enum Element{IGNIS, ELEKTRO, HYDROS, VITAS, TERRA, METALLUM, VENTUS, GLAKIES, LUX, NYX};
typedef unsigned short score;

/*Y'know, I be using things*/
using std::string;

/*Classes interfaces*/
class Aether{
	private:
		Element affinity1;
		Element affinity2;
		unsigned short concentration;
	public:
		Aether();
		Aether(Element, Element);
		unsigned short getConcentration(){return concentration;}
};

/* Five Aether objects*/
Aether Striking(IGNIS, ELEKTRO);
Aether Flowing(HYDROS, VITAS);
Aether Unbreakable(TERRA, METALLUM);
Aether Howling(VENTUS, GLAKIES);
Aether Polar(LUX, NYX);

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
		//Constructor
		Elementarium(string, Affinities aff);

		void setName(string);
		string getName(){return name;}
		Element getElementalAffinity();
		Aether getAethericalAffinity();
};
