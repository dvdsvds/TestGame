#include "Npc.h"

Npc::Npc(string name, ObjectType npcType, NpcRole role) :
	Object(name, HP, MP, attackPower, defensePower), npcType(npcType), role(role) {}

