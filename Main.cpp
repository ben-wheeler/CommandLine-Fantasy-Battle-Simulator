#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Elf.h"
#include "Human.h"
#include "Orc.h"

//reads in external functions
extern Player * setRace(string input);
extern int setType(string type, Player * character);
extern Player * randomOpponent();
extern void fight(Player * character, Player * computer);


using namespace std;

int main(){
	Player * character; //Create character as a player
	Player * computer; //Create computer as a player
	string race; //initilise race variable
	string pName; //initilise pName variable
	string pAge; //initilise temp variable
	string input; //initilise input variable
	string temp;

	//Get input from user to set the race for the character
	cout << "Firstly, select a race for your character, please enter a number:\n  1 = Elf\n  2 = Human\n  3 = Orc" << endl; 
	cin >> race;
	character = setRace(race);

	//Get input from user to set the type for the character
	cout << "Select a class for your character, please enter a number:\n  1 = Wizard\n  2 = Warrior\n  3 = Rogue" << endl; 
	cin >> input;	
	character->type = setType(input, character);

	//Get input from user to set the name for the character
	cout << "Please enter a name your character or enter 'Random' for randomly generated name:" << endl; 
	cin >> pName;
	character->setName(pName);

	//Get input from user to set the age for the character
	cout << "Please enter the age of your character or enter 'Random' for randomly generated age between 0 and 100:" << endl; 
	cin >> pAge;
	character->setAge(pAge);

	//Use input for race and type to generate the stats for the character
	character->setRaceStats(); //Add the race stats to the base stats for the character
	character->setTypeStats(); //Add the type stats to the base + race stats for the character
	cout << endl;

	character->trait();
	cout << endl;

	//printing character stats
	cout << character->name << "'s information" << endl; 
	character->printStats();

	cout << endl;
	cout << "Enter any letter to continue..." << endl;
	cin >> temp;
	cout << endl;

	//creating an opponent for the user to battle
	computer = randomOpponent(); // computer makes a randomly generated opponent
	computer->setName("Random"); // computer makes a randomly generated opponent name
	computer->setAge("Random"); //computer makes a randomly generated opponent age

	//printing opponents stats
	cout << "\n Opponent's information" << endl; 
	computer->printStats();
	cout << endl;

	fight(character,computer);

}
