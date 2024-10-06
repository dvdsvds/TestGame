#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

enum ItemType {
	weapon,
	secondWeapon,
	helmet,
	pants,
	shirt
};

class Item {

static random_device rd_Item;
static mt19937 i;

private:
	string name;
	int attackPower;
	int defensePower;
	int requireLevel;
	int hp;
	int durability;
	ItemType itemType;
public:
	Item(string name, ItemType itemtype, int addHP, int addAP, int addDP, int Durability ,int rl);

	string getName();

	int getAttackPower();
	int getDefensePower();
	int getRequireLevel();
	int getHp();
	int getDurability();	
	void printInfo() const;

	static const vector<Item> WeaponList;
	static const vector<Item> SecondWeaponList;
	static const vector<Item> ShirtList;
	static const vector<Item> HelmetList;
	static const vector<Item> PantsList;

	static Item getRandomItem();
	static Item getRandomItemFromList(const vector<Item>& itemList);

	string typeToString() const;
};

#endif