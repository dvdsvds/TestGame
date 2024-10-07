#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"


class Player : public Object {
private:
	int exp;
	ObjectType playerType;
	int lvl;
public:
	Player(const std::string& name, ObjectType playerType, int lvl, int exp);

	void setExp(int newExp);
	int getExp() const;

	void setLevel(int newlevel);
	int getLevel() const;

	ObjectType getType() const;

	void printInfo() const;
	void updateStats(int hp, int attackPower, int defensePower);

	std::string typeToString() const;

};


#endif