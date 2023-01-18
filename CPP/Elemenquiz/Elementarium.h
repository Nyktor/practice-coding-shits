/* 
	Author: Nyktor
	Date: Mergaia, 26 from Yule of 12023 HE
	File: header file
	Description: it's a header :0
*/

#include <iostream>
#include <string>

/*User defined datatypes*/
enum eElement{IGNIS, ELEKTRO, HYDROS, VITAS, TERRA, METALLUM, VENTUS, GLAKIES, LUX, NYX, elemNULL};
enum eAether{STRIKING, FLOWING, UNBREAKABLE, HOWLING, POLAR, aethNULL};

typedef unsigned short score;

/*Y'know, I be using things*/
using std::string;

/* Useful functions */
string getElementStringByID(int id);
string getAetherStringByID(int id);

/*Classes interfaces*/
class Aether{
	private:
		eAether e;
		eElement affinity1;
		eElement affinity2;
		unsigned short concentration;
	public:
		Aether(){
			affinity1 = elemNULL;
			affinity2 = elemNULL;
			e = aethNULL;
		}
		Aether(eElement e1, eElement e2, eAether ae){
			affinity1 = e1;
			affinity2 = e2;
			e = ae;
		};

		string getName(){return getAetherStringByID(e);}
		unsigned short getConcentration(){return concentration;}
		eAether getEnum(){return e;}
};

/* Five Aether objects*/
Aether Striking(IGNIS, ELEKTRO, STRIKING);
Aether Flowing(HYDROS, VITAS, FLOWING);
Aether Unbreakable(TERRA, METALLUM, UNBREAKABLE);
Aether Howling(VENTUS, GLAKIES, HOWLING);
Aether Polar(LUX, NYX, POLAR);

/* Class for ALL affinities, elemental AND aetherical*/
class Affinities{
	private:
		score Ignis, Elektro, Hydros, Vitas, Terra, 
			  Metallum, Ventus, Glakies, Lux, Nyx;

		score AllElements[10];
		score AllAethers[5];
	public:
		Affinities(){
			for(int i = 0; i < 10; i++){
				AllElements[i] = 0;
			}
		}
		Affinities(score scores[10]){
			Ignis = scores[0];
			Elektro = scores[1];
			Hydros = scores[2];
			Vitas = scores[3];
			Terra = scores[4];
			Metallum = scores[5];
			Ventus = scores[6];
			Glakies = scores[7];
			Lux = scores[8];
			Nyx = scores[9];

			for(int i = 0; i < 10; i++){
				AllElements[i] = scores[i];
			}

			AllAethers[0] = Ignis + Elektro;
			AllAethers[1] = Hydros + Vitas;
			AllAethers[2] = Terra + Metallum;
			AllAethers[3] = Ventus + Glakies;
			AllAethers[4] = Lux + Nyx;
		}

		score getElementalAffinity(int element){return AllElements[element];}

		score getStrikingAffinity(){return AllAethers[0];}
		score getFlowingAffinity(){return AllAethers[1];}
		score getUnbreakableAffinity(){return AllAethers[2];}
		score getHowlingAffinity(){return AllAethers[3];}
		score getPolarAffinity(){return AllAethers[4];}

		eElement getKinElement(){
			eElement ele = elemNULL;
			score highest = 0;
			for(int i = 0; i < 10; i++){
				if(AllElements[i] > highest){
					highest = AllElements[i];
					ele = eElement(i);
				}
			}
			return ele;
		}
		
		Aether getKinAether(){
			Aether ae;
			score highest = 0;
			int highestId = -1;
			for(int i = 0; i < 5; i++){
				if(AllAethers[i] > highest){
					highest = AllAethers[i];
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
		score* getAllElementScores(){return AllElements;}
		score* getAllAetherScores(){return AllAethers;}
};

/* Class for an Elementarium*/
class Elementarium{
	private:
		string name;
		Affinities aff;
	public:
		Elementarium(){
			Affinities emptyAff;
			name = "";
			aff = emptyAff;
		}
		Elementarium(string iName, Affinities iAff){
			name = iName;
			aff = iAff;
		};
		Elementarium(string iName, score scores[10]){
			Affinities iAff(scores);
			name = iName;
			aff = iAff;
		};
		void setName(string iName){name = iName;};
		string getName(){return name;}
		Affinities getAffinities(){return aff;}
};

/* Useful functions */
string aetherNames[5] = {"STRIKING", "FLOWING", "UNBREAKABLE", "HOWLING", "POLAR"};
string elementNames[10] = {"IGNIS", "ELEKTRO", "HYDROS", "VITAS", "TERRA", "METALLUM", "VENTUS", "GLAKIES", "LUX", "NYX"};

string getElementStringByID(int id){
    return elementNames[id];
}
string getAetherStringByID(int id){
    return aetherNames[id];
}
