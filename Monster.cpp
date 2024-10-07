#include "Monster.h"

Monster::Monster(const std::string& name, int lvl, int giveExp, int hp, int mp, int attackPower, int defensePower) :
	Object(name, hp, mp, attackPower, defensePower), giveExp(giveExp), lvl(lvl){}

void Monster::setName(const std::string& newName) { name = newName; }
const std::string& Monster::getName() const { return name; }

int Monster::getGiveExp() const { return giveExp; }

void Monster::printInfo() const {
	std::cout << "NAME        : " << getName() << std::endl;
	std::cout << "HP          : " << getHP() << std::endl;
	std::cout << "MP          : " << getMP() << std::endl;
	std::cout << "LEVEL       : " << lvl << std::endl;
	std::cout << "ATTACKPOWER : " << getAttackPower() << std::endl;
}

std::random_device Monster::rd_Monster;
std::mt19937 Monster::m(Monster::rd_Monster());

const std::vector<Monster> Monster::EasyMonsterList = {
	Monster("Slim", 1, 1, 10, 0, 1, 1),
	Monster("Wolf", 1, 2, 12, 0, 2, 1),
	Monster("Goblin", 1, 4, 10, 0, 1, 1)
};

Monster Monster::AppeardRandomFromList(const std::vector<Monster>& monsterList) {
	if (monsterList.empty()) {
		throw std::runtime_error("Item list is empty");
	}

	std::uniform_int_distribution<size_t> dis(0, monsterList.size() - 1);
	size_t randomIndex = dis(m);
	return monsterList[randomIndex];
};


Monster Monster::ApperedMonster() {
	std::uniform_int_distribution<size_t> listSelector(0, 0);

	int selectList = listSelector(m);
	switch (selectList) {
	case 0:
		return Monster::AppeardRandomFromList(Monster::EasyMonsterList);
		break;
	}

};