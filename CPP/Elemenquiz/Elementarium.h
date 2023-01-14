#include <iostream>
#include <string>
enum Element{IGNIS, ELEKTRO, HYDROS, VITAS, TERRA, METALLUM, VENTUS, GLAKIES, LUX, UMBRA};
enum Aether{STRIKING, FLOWING, UNBREAKABLE, HOWLING, POLAR};

using std::string;

class Elementarium{
	private:
		string name;
		int scores[10];
		Element eAffinity;
		Aether aAffinity;
	public:
		void setName(string);
		
};
