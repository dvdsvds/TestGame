#ifndef NPC_H
#define NPC_H

#include "Object.h"

enum NpcRole {
	Guide,
	Merchant,
	QuestGiver,
	Informant,
	Inhabitant,
	BlackSmith
};

class Npc : public Object {
private:
	std::string name;
	ObjectType npcType;
	NpcRole role;
public:
	Npc(const std::string& name, ObjectType npcType, NpcRole role);
	void printInfo() const;
};
#endif
