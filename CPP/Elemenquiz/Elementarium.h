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
		}

		score getElementalAffinity(int element){return AllElements[element];}

		score getStrikingAffinity(){return striking;}
		score getFlowingAffinity(){return flowing;}
		score getUnbreakableAffinity(){return unbreakable;}
		score getHowlingAffinity(){return howling;}
		score getPolarAffinity(){return polar;}

		eElement getKinElement(){
			eElement e;
			score highest = 0;
			score* pAllElements = getAllElementScores();
			for(int i = 0; i < 10; i++){
				if(pAllElements[i] > highest){
					highest = pAllElements[i];
					e = eElement(i);
				}
			}
			return e;
		}
		
		Aether getKinAether(){
			Aether ae;
			score highest = 0;
			score* pAllAethers = getAllAetherScores();
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
		score* getAllElementScores(){
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
		
		score* getAllAetherScores(){
			static score allAethers[5];
			
				allAethers[0] = getStrikingAffinity();
				allAethers[1] = getFlowingAffinity();
				allAethers[2] = getUnbreakableAffinity();
				allAethers[3] = getHowlingAffinity();
				allAethers[4] = getPolarAffinity();
			
			return allAethers;
		}
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
		Elementarium(string iName, score* scores){
			Affinities iAff(scores);
			name = iName;
			aff = iAff;
		};
		void setName(string iName){name = iName;};
		string getName(){return name;}
		Affinities getAffinities(){return aff;}
};

string aetherNames[5] = {"STRIKING", "FLOWING", "UNBREAKABLE", "HOWLING", "POLAR"};
string elementNames[10] = {"IGNIS", "ELEKTRO", "HYDROS", "VITAS", "TERRA", "METALLUM", "VENTUS", "GLAKIES", "LUX", "NYX"};

/* Useful functions */
string getElementStringByID(int id){
    return elementNames[id];
}
string getAetherStringByID(int id){
    return aetherNames[id];
}
