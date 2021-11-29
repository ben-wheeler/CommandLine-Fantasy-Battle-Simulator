#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

extern bool isNumber(string check);


Player::Player(){ // default case
	for(int i = 0; i < 5; i++){
		stats[i] = 14; // sets the stats to 14 as a base
	}
    string name = " "; // sets empty name
    age = 0; // sets age to 0
    race = 0; // sets race to unknown
    type = 0; // sets type to unknown
    computerCreated = 0; // sets computerCreated to 0
}

//setting the age of the player's character
void Player::setAge(string tempAge){
	int pAge = 0;
	bool loopTrigger = 1;
	while(loopTrigger == 1){
		if(tempAge == "Random" || tempAge == "random" || tempAge == "RANDOM"){
			srand (time(NULL));
			int i = (rand() % 100) + 1;
			age = i;
			if(computerCreated == 0){
				cout << "Your character is "<< age << " years old!" << endl;
			}
			loopTrigger = 0; //Stops the while loop if inout is correct
			pAge = 1;
		}
		if (isNumber(tempAge)){
			pAge = stoi(tempAge);
			if(pAge > 0 && pAge <= 100){
				age = pAge;
				if(computerCreated == 0){
					cout << "Your character is "<< age << " years old!" << endl;
				}
				loopTrigger = 0; //Stops the while loop if inout is correct
				break;
			}
		}
		if(tempAge == "exit"){
			exit (EXIT_FAILURE); //Stops the code if exit is inputted by user
		}
		if(pAge < 1 || pAge > 100){
			if(computerCreated == 0){ // 
				cout << "Invalid input, please ensure your character's age is greater than 0 and less than 100. \nPlease input either a number or 'Random':" << endl;
				cin >> tempAge;
			}
		}
	}
}

// Sets the bool computerCreated to true if the player pointer is a computer rather than a user
void Player::setComputerCreated(){
	computerCreated = 1;
}

//Returns the name of the character
string Player::getName(){
	return name;
}

//Prints all stats of a character
void Player::printStats(){
	cout << " Name: " << name << endl;
	cout << " Age: " << age << endl;
	cout << " Race: " << characterRace << endl;
	cout << " Type: " << characterType << endl;
	cout << " Stats:" << endl;
	cout << "       Strength: " << stats[0] << endl;
	cout << "       Constitution: " << stats[1] << endl;
	cout << "       Finesse: " << stats[2] << endl;
	cout << "       Intelligence: " << stats[3] << endl;
	cout << "       Perception: " << stats[4] << endl;
}

Player::~Player(){
}