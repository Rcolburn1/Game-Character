// Robert Colburn
// CS_355_01
// Assignment #3
// 9/1/23
// Implementation file for functions declared withing GameCharacter.h

#include "GameCharacter.h"
#include <fstream>

GameCharacter::GameCharacter(const string& charName, int maxHP, int currentAtkPoints, int currentDefPoints, bool currentIsAlive)
{
	name = charName;
	maxHealth = maxHP;
	hitPoints = maxHP;
	atkPoints = currentAtkPoints;
	defPoints = currentDefPoints;
	isAlive = currentIsAlive;
}

void GameCharacter::getName()
{
	cout << name <<endl;
}

void GameCharacter::getMaxHealth()
{
	cout << maxHealth << endl;
}

void GameCharacter::getHP()
{
	cout << hitPoints << endl;
}

void GameCharacter::getAP()
{
	cout << atkPoints << endl;
}

void GameCharacter::getDP()
{
	cout << defPoints << endl;
}

void GameCharacter::getLife()
{
	cout << isAlive << endl;
}

void GameCharacter::takeDamage(int damage)
{
	hitPoints = hitPoints - damage;
	if(hitPoints <= 0)
	{
		isAlive = false;
		cout << name << " HAS BEEN DEFEATED!" << endl;
	}
}

void GameCharacter::attack(GameCharacter& target)
{
	int damage = 0;

	damage = atkPoints - target.defPoints;

	if(damage > 0)
	{
		target.takeDamage(damage);
	}

	else
	{
		cout << name << " can't get past " << target.name << "'s defenses!! 0 damage dealt!" << endl;
	}
}

void GameCharacter::saveToFile(const string& filename)
{
	ofstream outfile(filename);

	if(outfile.fail())
	{
		cout << "Failed To Open File For Writing." << endl;
		exit(1);
	}

	outfile << name << endl;
	outfile << maxHealth << endl;
	outfile << hitPoints << endl;
	outfile << atkPoints << endl;
	outfile << defPoints << endl;
	outfile << isAlive << endl;

	lastSaveTime = ctime(&now);

	cout << "File Saved." << endl;
}

void GameCharacter::loadFromFile(const string& filename)
{
	ifstream inFile(filename);
	string  Lname = " ";
	int LoadMaxHealth = 0;
	int LoadHitPoints = 0;
	int LoadAtkPoints = 0;
	int LoadDefPoints = 0;
	bool LoadIsAlive = false;

	if(inFile.fail())
	{
		cout << "Failed To Open File For Reading." << endl;
	}

	getline(inFile, name);
	inFile >> maxHealth;
	inFile >> atkPoints;
	inFile >> defPoints;
	inFile >> isAlive;

	name = Lname;
	hitPoints = LoadHitPoints;
	atkPoints = LoadAtkPoints;
	defPoints = LoadDefPoints;
	isAlive = LoadIsAlive;
	
	//optional lines to potentially allow save files to be loaded from main to create new character
	//or track characters across sessions.
	//inFile >> LoadHitPoints;
	//hitPoints = LoadHitPoints;
	//GameCharacter name(name, maxHealth, hitPoints, atkPoints, defPoints, isAlive);
}

void GameCharacter::operator=(const GameCharacter& target)
{
	maxHealth = target.maxHealth;
	hitPoints = target.hitPoints;
	atkPoints = target.atkPoints;
	defPoints = target.defPoints;
	isAlive = target.isAlive;
}

void GameCharacter::operator+(const GameCharacter& partner)
{
	int newMaxHealth;
	int newHitPoints;
	int newAtkPoints;
	int newDefPoints;
	bool newIsAlive;

	newMaxHealth = maxHealth + partner.maxHealth;
	newHitPoints = (hitPoints + partner.hitPoints) / 2;
	newAtkPoints = (atkPoints + partner.atkPoints) / 2;
	newDefPoints = (defPoints + partner.defPoints) / 2;
	newIsAlive = true;
}

bool GameCharacter::operator>(const GameCharacter& target)
{
	if(hitPoints > target.hitPoints)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool GameCharacter::operator<(const GameCharacter& target)
{
	if(hitPoints < target.hitPoints)
	{
		return true;
	}

	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const GameCharacter& PC)
{
	os << "Name: " <<  PC.getName << endl;
	os << "Max Health: " << PC.getMaxHealth << endl;
	os << "Current Hit Points: " << PC.getHP << endl;
	os << "Attak Points: " << PC.getAP << endl;
	os << "Defense Points: " << PC.getDP << endl;
	os << "Alive?: " << PC.getLife << endl;
}

void GameCharacter::displayDateTimeOfLastSave()
{
	char* dt = lastSaveTime;

	cout << "Last saved on: " << dt << endl;
}
