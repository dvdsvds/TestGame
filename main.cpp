#include <iostream>
#include "Item.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Npc.h"
#include "system.h"

using namespace std;

int main() {
	SetConsoleFont(10);
	// player setting
	srand(static_cast<unsigned int>(time(NULL)));
	string name;
	int choice;

	cout << "Can you tell me your name before entering in this world?" << endl;
	cin >> name;

	cout << endl;
	cout << "What do you want to be in the world?" << endl;
	cout << "(1)Human (2)Oak (3)Elf" << endl;
	choice = getValidIntegerInput();

	// choose the player's race
	ObjectType raceType;
	switch (choice) {
	case 1:
		raceType = Human;
		break;
	case 2:
		raceType = Oak;
		break;
	case 3:
		raceType = Elf;
		break;
	default : 
		raceType = Human;
		break;
	}

	Player p(name, raceType, 1, 0);
	cout << "Ok. You chose " << p.typeToString() << ". That is a good choice." << endl;
	cout << endl;
	p.printInfo();
	cout << endl;
	// the end of player setting

	while (true) {
		// game logic
		cout << "You are walking down the street." << endl;
		cout << "There are three signpost in front of you." << endl << endl;
		cout << "What would you do?" << endl;
		cout << "(1)Go out of the villiage (2)Go to forge (3)Go to shop" << endl ;
		choice = getValidIntegerInput();

		switch (choice) {
		case 1: // Go out of the villiage
			while (true) {
				cout << endl;
				cout << "You came out of the villiage." << endl;
				
				Monster am = Monster::ApperedMonster();
				cout << endl;
				cout << am.getName() << " has appeared" << endl;
				am.printInfo();

				while (am.getHP() > 0 && p.getHP() > 0) {
					cout << endl;
					cout << "What do you want to do?" << endl;
					cout << "1. attack" << endl << "2. run" << endl ;
					choice = getValidIntegerInput();
					cout << endl;

					if (choice == 1) {
						am.setHP(am.getHP() - p.getAttackPower());
						am.printInfo();
						cout << endl;

						p.setHP(p.getHP() - am.getAttackPower());
						p.printInfo();
						if (p.getHP() <= 0) {
							cout << p.getName() << " has been slain by " << am.getName() << endl;
							return 0;
						}

						if (am.getHP() <= 0) {
							Item getItem = Item::getRandomItem();
							cout << endl;
							cout << am.getName() << " has been slain by " << p.getName() << "'s weapon." << endl;
							cout << "You've got an " << getItem.getName() << endl;
							cout << endl;
							getItem.printInfo();
							cout << endl;
							cout << "Would you like to equip? " << endl;
							cout << "(1) y (2) n" << endl ;
							choice = getValidIntegerInput();
							cout << endl;

							if (choice == 1) {
								if (p.getLevel() >= getItem.getRequireLevel()) {
									cout << "You equiped " << getItem.getName() << endl;
									p.updateStats(getItem.getHp(), getItem.getAttackPower(), getItem.getDefensePower());
									p.printInfo();
								} else {
									cout << "You can't equiped " << getItem.getName() << endl;
									cout << "The Reason : Require Level " << getItem.getRequireLevel() << endl;
								}
							} else {
								cout << "You didn't equip " << getItem.getName() << endl;
							}

							p.setExp(p.getExp() + am.getGiveExp());

							if (p.getExp() >= 10) {
								p.setLevel(p.getLevel() + 1);
								p.setExp(0);
								cout << "Level UP" << endl;
								cout << "You have become level " << p.getLevel() << endl;
							}
							break;
						}

				} else if (choice == 2) {
					cout << "successed" << endl;
					break;
				} else {
					cout << "Try to choose again." << endl;
					continue;
				}
			}
		}
		break;

		case 2: { // Go to forge
			int subChoice;
			Npc BlackSmithJames("James", ObjectType::Human, NpcRole::BlackSmith);
			cout << "Hi. My name is " << BlackSmithJames.getName() << endl;
			cout << "What would you like?" << endl;
			cout << "(1)Forge (2)Fix (3)Disassable (4)Exit" ;
			subChoice = getValidIntegerInput();

			switch (subChoice) {
			case 1: // Forge
				break;
			case 2: // Fix
				break;
			case 3: // Disassable
				break;
			case 4: //Exit
				break;
			}
			break;
		}
		case 3: // Go to shop
			break;
		default:
			cout << "Invaild choice, Please try again" << endl;
			continue;
		}
	}
	return 0;
}