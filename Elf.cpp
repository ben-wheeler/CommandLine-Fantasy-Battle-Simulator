//This is the Elf cpp file, it contains all of the elf functions

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Elf.h"

using namespace std;

Elf::Elf(){
	race = 1; //Sets the users race to 1, the number that corresponds with Elf 
}

//Adjusts the users stats to fit with their race selection
void Elf::setRaceStats(){ //
	stats[2] += 2;
	stats[3] += 3;
	stats[4] += 1;
}

//Adjusts the users stats to fit with their type selection
void Elf::setTypeStats(){
			switch(type) {
			case 1: //This runs if the user has selected Wizard (type = 1)
			stats[2] += 1;
			stats[3] += 3;
			stats[4] += 2;
			break;
			case 2: //This runs if the user has selected Warrior (type = 2)
			stats[1] += 3;
			stats[2] += 2;
			stats[3] += 1;
			break;
			case 3: //This runs if the user has selected Rouge (type = 3)
			stats[2] += 3;
			stats[3] += 1;
			stats[4] += 2;
			break;
	}
}

//This checks if the player picks random of if they enter their own name
void Elf::setName(string pName){
	if(pName == "Random" || pName == "random" || pName == "RANDOM"){
		srand (time(NULL)); //This choses a random seed for the RNG
		int i = rand() % 100; //This choses a random number between 1-100

		ifstream file; //Creates file of type class to read in a file 

		string inputString; //Creates a string called inputString
		vector<string> generatedNames; //Creates a vector called generatedNames
		file.open("elfNames.txt"); //Opens the file elfNames.txt
		while(file>>inputString){
			generatedNames.push_back(inputString); 
		}
		file.close(); //Closes elfNames.txt

		name = generatedNames[i]; //takes the random number from the begining and sets the varible name to the ith value of the vector
		if(computerCreated == 0){
			cout << "Your character was randomly named: "<< name << "!" << endl; //Prints the users random name
		}
	}
	else{
		name = pName;//Sets the users input as their name
		if(computerCreated == 0){
			cout << "Your character was successfully named: "<< name << "!" << endl;
		}
	}
}

void Elf::trait(){
		switch(type) {
			case 1: //This runs if the user has selected Wizard (type = 1)
			cout << "A mystical fog appears, " << name << " emerges from within:" << endl; 
			break;
			case 2: //This runs if the user has selected Warrior (type = 2)
			cout << name << " takes a swig out of jug, spilling its contents on their pants:" << endl; 
			break;
			case 3: //This runs if the user has selected Rouge (type = 3)
			cout << name << " does a dance!" << endl;
			break;
	}
}
