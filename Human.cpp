//This is the Human cpp file, it contains all of the human functions

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Human.h"

using namespace std;

Human::Human(){  
	race = 2; //Sets the users race to 2, the number that corresponds with human
}

//Adjusts the users stats to fit with their race selection
void Human::setRaceStats(){
	stats[0] += 1;
	stats[1] += 1;
	stats[2] += 2;
	stats[3] += 1;
	stats[4] += 1;
}

//Adjusts the users stats to fit with their type selection
void Human::setTypeStats(){
		switch(type) {
			case 1://This runs if the user has selected Wizard (type = 1)
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
void Human::setName(string pName){
	if(pName == "Random" || pName == "random" || pName == "RANDOM"){
		
		srand (time(NULL)); //This choses a random seed for the RNG
		int i = rand() % 100; //This choses a random number between 1-100
		
		ifstream file; //Creates file of type class to read in a file 

		string inputString; //Creates a string called inputString
		vector<string> generatedNames; //Creates a vector called generatedNames
		file.open("humanNames.txt"); //Opens the file humanNames.txt
		while(file>>inputString){
			generatedNames.push_back(inputString); //Puts all of the names from humanNames.txt to the vector generatedNames
		}
		file.close(); //Closes humanNames.txt

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

void Human::trait(){
		switch(type) {
			case 1: //This runs if the user has selected Wizard (type = 1)
				cout << name <<  " does something strange..." << endl;
				cout << "nothing happens" << endl;
			break;
			case 2: //This runs if the user has selected Warrior (type = 2)
				cout << name <<  " does something strange..." << endl;
				cout << "nothing happens" << endl;
			break;
			case 3: //This runs if the user has selected Rouge (type = 3)
				cout << name <<  " does something strange..." << endl;
				cout << "nothing happens" << endl;
			break;
	}
}