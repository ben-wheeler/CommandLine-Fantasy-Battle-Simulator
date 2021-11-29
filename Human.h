// the H file for the human class

#include <iostream>
#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

class Human: public Player{ //This sets the class Human as a sub-class of Player
	public:
		Human();
		void setRaceStats(); //This adds the Human modifers to the base stats
		void setName(string pName); //This takes the pName varible and sets that to the name varible
		void setTypeStats(); //Takes the type of the character and ajusts the stats accordingly
		void trait();
	};
#endif