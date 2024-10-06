#include "Monster.h"

Monster::Monster(string name, int lvl, int giveExp, int hp, int mp, int attackPower, int defensePower) :
	Object(name, HP, MP, attackPower, defensePower), name(name), giveExp(giveExp), lvl(lvl){}

void Monster::setName(string newName) { name = newName; }
string Monster::getName() const { return name; }

int Monster::getGiveExp() const { return giveExp; }

void Monster::printInfo() const {
	cout << "NAME        : " << getName() << endl;
	cout << "HP          : " << getHP() << endl;
	cout << "MP          : " << getMP() << endl;
	cout << "LEVEL       : " << lvl << endl;
	cout << "ATTACKPOWER : " << getAttackPower() << endl;
}

random_device Monster::rd_Monster;
mt19937 Monster::m(Monster::rd_Monster());

const vector<Monster> Monster::EasyMonsterList = {
	Monster("Slim", 1, 1, 10, 0, 1, 1),
	Monster("Wolf", 1, 2, 12, 0, 2, 1),
	Monster("Goblin", 1, 4, 10, 0, 1, 1)
};

Monster Monster::AppeardRandomFromList(const vector<Monster>& monsterList) {
	if (monsterList.empty()) {
		throw runtime_error("Item list is empty");
	}

	uniform_int_distribution<size_t> dis(0, monsterList.size() - 1);
	size_t randomIndex = dis(m);
	return monsterList[randomIndex];
};


Monster Monster::ApperedMonster() {
	uniform_int_distribution<size_t> listSelector(0, 0);

	int selectList = listSelector(m);
	switch (selectList) {
	case 0:
		return Monster::AppeardRandomFromList(Monster::EasyMonsterList);
		break;
	}

};