#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <random>

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
	std::string name;
public:
	Object(const std::string& name, int HP, int MP, int attackPower, int defensePower);

	const std::string& getName() const;
	void setName(const std::string& newName);

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
