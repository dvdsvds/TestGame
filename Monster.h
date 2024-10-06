#ifndef MONSTER_H
#define MONSTER_H

#include "Object.h"
class Monster : public Object {

static random_device rd_Monster;
static mt19937 m;

private:
	string name;
	int giveExp;
	int lvl;

public:
	Monster(string name, int lvl, int giveExp, int hp, int mp, int attackPower, int defensePower);

	void setName(string newName);
	string getName() const;

	int getGiveExp() const;
	void printInfo() const;

	static const vector<Monster> EasyMonsterList;
	static Monster ApperedMonster();
	static Monster AppeardRandomFromList(const vector<Monster>& monsterList);
};

#endif