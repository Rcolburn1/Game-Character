// Robert Colburn
// CS_355_01
// Assignment #3
// 9/1/2023
// Header file for the Game Character class. contains attributes and methods.

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

class GameCharacter
{
	//I'm sorry the original names hurt my soul, please forgive me.
	private:
		string name;
		int maxHealth;
		int hitPoints;
		int atkPoints;
		int defPoints;
		bool isAlive;
		time_t lastSaveTime; 


	public:
		GameCharacter(const string& charName, int maxHP, int  currentAtkPoints, int currentDefpoints, bool currentIsAlive);
		void getName();
		void getMaxHealth();
		void getHP();
		void getAP();
		void getDP();
		void getLife();
		void takeDamage(int damage);
		void attack(GameCharacter& target);
		void saveToFile(const string& filename);
		void loadFromFile(const string& filename);
		void operator= (const GameCharacter& target);
		void operator+ (const GameCharacter& partner);
		bool operator> (const GameCharacter& target);
		bool operator< (const GameCharacter& target);
		friend ostream operator<< (ostream& os, const GameCharacter& PC);
		void displayDateTimeOfLastSave();
		void displayTimeSinceLastSave();
};

#endif
