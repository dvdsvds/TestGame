#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>


enum ItemType {
	weapon,
	secondWeapon,
	helmet,
	pants,
	shirt
};

class Item {

static std::random_device rd_Item;
static std::mt19937 i;

private:
	std::string name;
	int attackPower;
	int defensePower;
	int requireLevel;
	int hp;
	int durability;
	ItemType itemType;
public:
	Item(const std::string& name, ItemType itemtype, int addHP, int addAP, int addDP, int Durability ,int rl);

	const std::string& getName() const;

	int getAttackPower() const;
	int getDefensePower() const;
	int getRequireLevel() const;
	int getHp() const;
	int getDurability() const;	
	void printInfo() const;

	static const std::vector<Item> WeaponList;
	static const std::vector<Item> SecondWeaponList;
	static const std::vector<Item> ShirtList;
	static const std::vector<Item> HelmetList;
	static const std::vector<Item> PantsList;

	static Item getRandomItem();
	static Item getRandomItemFromList(const std::vector<Item>& itemList);

	std::string typeToString() const;
};

#endif