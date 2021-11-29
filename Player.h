#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player{
    public:
        Player();

        //Initalising all of the Player varibles
        int stats[5];
        int age;
        int race;
        int type;
        bool computerCreated;

        string name;
        string characterType;
        string characterRace;

        //Initalising all of the Player functions that are virtual
        virtual void setRaceStats() = 0;
        virtual void setTypeStats() = 0;
        virtual void setName(string pName) = 0; 
        virtual void trait() = 0;

        
        void printStats();
        void setAge(string tempAge);
        int getAge();
        string getName();
        int getRace();
        void setComputerCreated();
        ~Player();
};
#endif