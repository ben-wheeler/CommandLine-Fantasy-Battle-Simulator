// the H file for the Orc class

#include <iostream>
#ifndef ORC_H
#define ORC_H

using namespace std;

class Orc: public Player{ //This sets the class Orc as a sub-class of Player
	public:
		Orc();
		void setRaceStats(); //This adds the Human modifers to the base stats
		void setName(string pName); //This takes the pName varible and sets that to the name varible
		void setTypeStats(); //Takes the type of the character and ajusts the stats accordingly
		void trait();
};
#endif