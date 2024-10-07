#ifndef MONSTER_H
#define MONSTER_H

#include "Object.h"
class Monster : public Object {

static std::random_device rd_Monster;
static std::mt19937 m;

private:
	int giveExp;
	int lvl;

public:
	Monster(const std::string& name, int lvl, int giveExp, int hp, int mp, int attackPower, int defensePower);

	void setName(const std::string& newName);
	const std::string& getName() const;

	int getGiveExp() const;
	void printInfo() const;

	static const std::vector<Monster> EasyMonsterList;
	static Monster ApperedMonster();
	static Monster AppeardRandomFromList(const std::vector<Monster>& monsterList);
};

#endif