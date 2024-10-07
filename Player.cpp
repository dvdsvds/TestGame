#include "Player.h"

Player::Player(const std::string& name, ObjectType playerType, int lvl, int exp) : 
	Object(name, 20, 20, 5, 0), exp(exp), playerType(playerType), lvl(lvl) {}

ObjectType Player::getType() const { return playerType; }

void Player::setLevel(int newLevel) { lvl = newLevel; }
int Player::getLevel() const { return lvl; }

void Player::setExp(int newExp) { exp = newExp; }
int Player::getExp() const { return exp; }


void Player::printInfo() const {
	std::cout << "NAME         : " << getName() << std::endl;
	std::cout << "TYPE         : " << typeToString() << std::endl;
	std::cout << "HP           : " << getHP() << std::endl;
	std::cout << "MP           : " << getMP() << std::endl;
	std::cout << "LEVEL        : " << getLevel() << std::endl;
	std::cout << "ATTACKPOWER  : " << getAttackPower() << std::endl;
	std::cout << "DEFENSEPOWER : " << getDefensePower() << std::endl;
}



void Player::updateStats(int hp, int attackPower, int defensePower) {
	setHP(getHP() + hp);
	setAttackPower(getAttackPower() + attackPower);
	setDefensePower(getDefensePower() + defensePower);
}

std::string Player::typeToString() const {
	switch (playerType) {
		case Human: return "Human";
		case Oak: return "Oak";
		case Elf: return "Elf";
		default: return "Unknown";
	}
}
