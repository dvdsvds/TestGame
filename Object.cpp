#include "Object.h"

Object::Object(string name, int HP, int MP, int ap, int dp) 
	: name(name), HP(HP), MP(MP), attackPower(ap), defensePower(dp) {}

void Object::setName(string newName) { name = newName; }
string Object::getName() const { return name; }

void Object::setHP(int newHP) { HP = newHP; }
int Object::getHP() const { return HP; }

void Object::setMP(int newMP) { MP = newMP; }
int Object::getMP() const { return MP; }

int Object::getAttackPower() const { return attackPower; }
void Object::setAttackPower(int newAttackPower) { attackPower = newAttackPower; }

int Object::getDefensePower() const { return defensePower; }
void Object::setDefensePower(int newDefensePower) { defensePower = newDefensePower; }