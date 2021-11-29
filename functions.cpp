//THis file contains all of function definitions of the functions called up in main and the other code 

#include <iostream>
#include <string>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Player.h"
#include "Elf.h"
#include "Human.h"
#include "Orc.h"

using namespace std;

// This check if the players input is a number or not to prevent errors
bool isNumber(string check){
	for (int i = 0; i < check.length(); i++){
		if (isdigit(check[i]) == false){ //Checks if check is a number
			return false; //Returns false if the player does not enter a number 
		}
	}
	return true;
}

Player * setRace(string input){
	Player * character = NULL;
	bool loopTrigger = 1; //initalises loopTrigger

	if(input == "exit"){
		exit (EXIT_FAILURE); //Stops the code if exit is inputted by user
	}
	
	while(loopTrigger == 1){
		int race = 0; //initalises Race
		if (isNumber(input)){
			race = stoi(input); //Changes the input from a string to a number if 
		}
		if(race == 1 || race == 2 || race == 3){ //checks if input is 1, 2 or 3
			switch(race) {
				case 1:
				character = new Elf;
				character->characterRace = "Elf"; // sets characterRace to Elf
				cout << "You have chosen Elf!" << endl; //prints users race
				loopTrigger = 0; //Ends the while loop
				return character;//Returns the player * character
				break;
				case 2:
				character = new Human;
				character->characterRace = "Human"; // sets characterRace to Human
				cout << "You have chosen Human!" << endl;//prints users race
				loopTrigger = 0; //Ends the while loop
				return character;//Returns the player * character
				break;
				case 3:
				character = new Orc;
				character->characterRace = "Orc"; // sets characterRace to Orc
				cout << "You have chosen Orc!" << endl;//prints users race
				loopTrigger = 0; //Ends the while loop
				return character;//Returns the player * character
				break;
			}
		}
		else{
			//Reasks for the users input
			cout << "Incorrect input, please enter a number:\n  1 = Elf\n  2 = Human\n  3 = Orc" << endl;
			cin >> input;
		}
	}
	return character; //Returns the player * character
}

int setType(string input, Player * character){
	character->characterType = " "; //sets the characterType to blank
	bool loopTrigger = 1; //initalises loopTrigger

	if(input == "exit"){
		exit (EXIT_FAILURE); //Stops the code if exit is inputted by user
	}
	while(loopTrigger == 1){
		int type = 0;
		if (isNumber(input)){
			type = stoi(input);
		}
		if(type == 1 || type == 2 || type == 3){
			switch(type) {
				case 1: //checks if the user has inputted 1
				character->characterType = "Wizard"; // sets characterType to Wizard
				cout << "You are a Wizard " << character->characterRace << "!" << endl;
				loopTrigger = 0; //Ends the while loop
				return 1;
				break;
				case 2://checks if the user has inputted 2
				character->characterType = "Warrior"; // sets characterType to Warrior
				cout << "You are a Warrior " << character->characterRace << "!" << endl;
				loopTrigger = 0; //Ends the while loop
				return 2;
				break;
				case 3://checks if the user has inputted 3
				character->characterType = "Rogue"; // sets characterType to Rogue
				cout << "You are a Rogue " << character->characterRace << "!" << endl;
				loopTrigger = 0; //Ends the while loop
				return 3;
				break;
			}
		}
		if(type < 1 || type > 3){
			//Reasks for the users input
			cout << "Incorrect input, please enter a number:\n  1 = Wizard\n  2 = Warrior\n  3 = Rogue" << endl;
			cin >> input;
		}
	}
	return 0;
}

// random opponent generator
Player * randomOpponent(){

	Player * computer; //Initalises the computer Player *

	// random number is generatored
	srand(time(NULL));
	int random = (rand() % 3) + 1;

	// creates race, avoiding previous function due to not wanting c out
	switch(random) {
		case 1:
		computer = new Elf;
		computer ->characterRace = "Elf" ;
		break;
		case 2:
		computer = new Human;
		computer ->characterRace = "Human";
		break;
		case 3:
		computer = new Orc;
		computer ->characterRace = "Orc";
		break;
	}

	// creates type, avoiding previous function due to not wanting c out
	switch(random) {
		case 1:
		computer->characterType = "Wizard";
		computer->type = 1;
		break;
		case 2:
		computer->characterType = "Warrior";
		computer->type = 2;
		break;
		case 3:
		computer->characterType = "Rogue";
		computer->type = 3;
		break;
	}

	cout << "\n Your computer creates a " << computer->characterType << " " << computer->characterRace << " to battle your character!!" << endl;
	computer-> setComputerCreated();

	computer->setName("Random"); //Randomises the computers name
	computer->setAge("Random"); //Randomises the computers age

	computer->setRaceStats(); //Add the race stats to the base stats for the character
	computer->setTypeStats(); //Add the type stats to the base + race stats for the character

	return computer;
}


void fight(Player * character, Player * computer){
	srand(time(NULL)); //randomises the random seed
	int random = (rand() % 5); //choses a random number
	string temp; //intalises a temp string

	cout << "The character your computer made decides to fight you with its ";
	switch(random){ //This checks the random number chosen above and picks the stat associated with it as the stat that will be tested
		case 0:
		cout << "Strength" << endl;

		cout << endl;
		cout << "Enter any letter to continue..." << endl;
		cin >> temp;
		cout << endl;

		cout << "Your character has a strength of " << character->stats[0] << ". The computer has a strength of " << computer->stats[0] << "." << endl;
		break;
		case 1:
		cout << "Constitution" << endl;

		cout << endl;
		cout << "Enter any letter to continue..." << endl;
		cin >> temp;
		cout << endl;

		cout << "Your character has a constitution of " << character->stats[1] << ". The computer has a constitution of " << computer->stats[1] << "." << endl;
		break;
		case 2:
		cout << "Finesse" << endl;

		cout << endl;
		cout << "Enter any letter to continue..." << endl;
		cin >> temp;
		cout << endl;

		cout << "Your character has a finesse of " << character->stats[2] << ". The computer has a finesse of " << computer->stats[2] << "." << endl;
		break;
		case 3:
		cout << "Intelligence" << endl;

		cout << endl;
		cout << "Enter any letter to continue..." << endl;
		cin >> temp;
		cout << endl;

		cout << "Your character has a intelligence of " << character->stats[3] << ". The computer has a intelligence of " << computer->stats[3] << "." << endl;
		break;
		case 4:
		cout << "Perception" << endl;

		cout << endl;
		cout << "Enter any letter to continue..." << endl;
		cin >> temp;
		cout << endl;

		cout << "Your character has a perception of " << character->stats[4] << ". The computer has a perception of " << computer->stats[4] << "." << endl;
		break;
	}
	//These print a different message depending on whether you win, lose or draw
	if(character->stats[random] > computer->stats[random]){
		cout << "Your character defends the attack and wins the battle. Congratulations" << endl;
	}
	if(character->stats[random] < computer->stats[random]){
		cout << "Your character fails to defend the attack and was slain in battle" << endl;
	}
	if(character->stats[random] == computer->stats[random]){
		cout << "You are both of equal skill, resulting in a draw." << endl;
	}
}