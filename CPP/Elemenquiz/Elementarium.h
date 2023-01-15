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
//enum Aether{STRIKING, FLOWING, UNBREAKABLE, HOWLING, POLAR};

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

class Affinities{
	private:

};

class Elementarium{
	private:
		string name;
		int scores[10];
		Element eAffinity;
		Aether aAffinity;
	public:
		void setName(string);
		string getName(){return name;}
		Element getEAffinity(){return eAffinity;}
		Aether getAAffinity(){return aAffinity;}
		Elementarium(string, Element, Aether);
};
