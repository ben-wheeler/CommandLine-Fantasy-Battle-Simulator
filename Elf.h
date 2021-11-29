// the H file for the elf class

#include <iostream>
#ifndef ELF_H
#define ELF_H

using namespace std;

class Elf: public Player{ //Sets the Elf class as a sub-class of Player
    public:
	    Elf();
	 	void setRaceStats(); //This adds the Human modifers to the base stats
		void setName(string pName); //This takes the pName varible and sets that to the name varible
		void setTypeStats(); //Takes the type of the character and ajusts the stats accordingly
		void trait(); //Return the trait of the character
};
#endif