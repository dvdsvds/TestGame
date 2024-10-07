#include "item.h"

Item::Item(const std::string& name, ItemType itemType, int addHP, int addAP, int addDP, int durability, int rl)
	: name(name), itemType(itemType), hp(addHP), attackPower(addAP), defensePower(addDP), durability(durability), requireLevel(rl) {}

const std::string& Item::getName() const { return name; }
int Item::getAttackPower() const { return attackPower; }
int Item::getDefensePower() const { return defensePower; }
int Item::getRequireLevel() const { return requireLevel; }
int Item::getHp() const { return hp; }
int Item::getDurability() const { return durability; }

void Item::printInfo() const {
	std::cout << "NAME          : " << name << std::endl;
	std::cout << "TYPE          : " << typeToString() << std::endl;
	std::cout << "HP            : " << hp << std::endl;
	std::cout << "ATTACKPOWER   : " << attackPower << std::endl;
	std::cout << "DEFENSEPOWER  : " << defensePower << std::endl;
	std::cout << "REQUIRE LEVEL : " << requireLevel << std::endl;
}

// item setting
std::random_device Item::rd_Item;
std::mt19937 Item::i(Item::rd_Item());

std::uniform_int_distribution<> weapon_ap(0, 5);
std::uniform_int_distribution<> second_hp(0, 3), second_ap(0, 2), second_dp(0, 2);
std::uniform_int_distribution<> helmet_hp(2, 4), helmet_dp(1, 3);

const std::vector<Item> Item::WeaponList = {
	//add hp, add ap, add dp, durability, requireLevel
	Item("Old Sword", ItemType::weapon, 0, weapon_ap(i), 0, 5, 1),
	Item("Old Hammer", ItemType::weapon, 0, weapon_ap(i), 0, 5, 1),
	Item("Wooden Bow", ItemType::weapon, 0, weapon_ap(i), 0, 5, 1)
};

const std::vector<Item> Item::SecondWeaponList = {
	//add hp, add ap, add dp, durability, requireLevel
	Item("Old ShortSword", ItemType::secondWeapon, 0, second_ap(i), 0, 5, 1), 
	Item("Wooden Sheild", ItemType::secondWeapon, second_hp(i), 0, second_dp(i), 5, 1)
};
/*
const std::vector<Item> Item::HelmetList = {
	//Item("Leather Hat", ItemType::helmet, )
};

const std::vector<Item> Item::ShirtList = {
	//todo
};

const std::vector<Item> Item::PantsList = {
	//todo
};
*/

Item Item::getRandomItemFromList(const std::vector<Item>& itemList) {
	std::uniform_int_distribution<> dis(0, itemList.size() - 1);

	if (itemList.empty()) {
		throw std::runtime_error("Item list is empty");
	}

	int randomIndex = dis(i);
	return itemList[randomIndex];
};
Item Item::getRandomItem() {
	std::uniform_int_distribution<> listSelector(0, 2);

	int selectList = listSelector(i);

	switch (selectList) {
	case 0:
		return Item::getRandomItemFromList(Item::WeaponList);
		break;
	case 1:
		return Item::getRandomItemFromList(Item::SecondWeaponList);
		break;
		/*
	case 2:
		return Item::getRandomItemFromList(Item::HelmetList);
		break;
	case 3:
		return Item::getRandomItemFromList(Item::ShirtList);
		break;
	case 4:
		return Item::getRandomItemFromList(Item::PantsList);
		break;
		*/
	}
}
std::string Item::typeToString() const {
	switch (itemType) {
		case weapon: return "Weapon";
		case secondWeapon: return "Second Weapon";
		default: return "Unknown";
	}
}
