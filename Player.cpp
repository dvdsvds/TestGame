#include "Player.h"

Player::Player(string name, ObjectType playerType, int lvl, int exp) : 
	Object(name, 20, 20, 5, 0), exp(exp), playerType(playerType), lvl(lvl) {}

ObjectType Player::getType() const { return playerType; }

void Player::setLevel(int newlvl) { lvl = newlvl; }
int Player::getLevel() const { return lvl; }

void Player::setExp(int newExp) { exp = newExp; }
int Player::getExp() const { return exp; }


void Player::printInfo() const {
	cout << "NAME         : " << getName() << endl;
	cout << "TYPE         : " << typeToString() << endl;
	cout << "HP           : " << getHP() << endl;
	cout << "MP           : " << getMP() << endl;
	cout << "LEVEL        : " << getLevel() << endl;
	cout << "ATTACKPOWER  : " << getAttackPower() << endl;
	cout << "DEFENSEPOWER : " << getDefensePower() << endl;
}



void Player::updateStats(int hp, int attackPower, int defensePower) {
	setHP(getHP() + hp);
	setAttackPower(getAttackPower() + attackPower);
	setDefensePower(getDefensePower() + defensePower);
}

string Player::typeToString() const {
	switch (playerType) {
		case Human: return "Human";
		case Oak: return "Oak";
		case Elf: return "Elf";
		default: return "Unknown";
	}
}
