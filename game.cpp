//Robert Colburn
//CS_355_01
//Assignment #3
//9/1/23
//This is the driver program for the  GameCharacter class, it will be used to create and interact with the class to test functions.

#include "GameCharacter.cpp"

int main()
{
	GameCharacter Warrior("Link", 150, 120, 130, true);
	GameCharacter Guardian("Zavala", 170, 100, 200, true);
	GameCharacter Mage("Gandalf", 100, 300, 100, true);
	GameCharacter Dummy("Training Dummy", 100, 100, 100, true);
	GameCharacter Fusion("Landalk", 0, 0, 0, false);

	
	cout << "Warrior's Name: " << Warrior.getName << endl;;
	cout << "Guardian's Defense points: " << Guardian.getDP << endl;
	cout << "Mage's Attack Points: " << Mage.getAP << endl;
	cout << "Warrior's Max health: " << Warrior.getMaxHealth << endl;
	cout << "Guardian's current hit points: " << Guardian.getHp;
	cout << "Is Mage alive?: " << Mage.getLife << endl;

	cout << "First Round: Warrior Vs. Mage:" << endl
	cout << "Warrior Attacks!" << end;
	Warrior.attack(Mage);
	cout << "Mage HP: " << Mage.getHp << endl;
	cout << "Does the Warrior have more health?" << endl;
	cout << Warrior > Mage;
		
	cout << "Second Round: Mage vs. Dummy:" << endl;
	cout << "Mage Attacks Dummy!" << endl;
	Mage.attack(Dummy);
	cout << "Does the Dummy Have more health?" << endl;
	cout << Mage < Dummy;

	cout <<"Secret Technique: FUSION" << endl;
	cout <<"Warrior is fusing with Mage!!!" << endl;
	Fusion = Warrior + Mage;

	cout << Fusion;

	Fusion.saveToFile("FusionChar.txt");
	cout << "Guardian attacks fusion" << endl;
	Guardian.attack(Fusion);

	cout << "Fusion HP: " << Fusion.getHP;

	Fusion.loadFromFile("FusionChar.txt");

	return 0;
