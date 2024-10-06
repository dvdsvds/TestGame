#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <random>

using namespace std;

enum ObjectType {
	Human,
	Oak,
	Elf
};

class Object {
protected:
	int HP;
	int MP;
	int attackPower;
	int defensePower;
	string name;
public:
	Object(string name, int HP, int MP, int attackPower, int defensePower);

	string getName() const;
	void setName(string newName);

	int getHP() const;
	void setHP(int newHP);

	int getMP() const;
	void setMP(int newMP);

	int getAttackPower() const;
	void setAttackPower(int newAttackPower);

	int getDefensePower() const;
	void setDefensePower(int newDefensePower);
};

#endif
