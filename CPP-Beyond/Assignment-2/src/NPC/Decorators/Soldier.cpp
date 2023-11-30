#include "Soldier.h"

#include <iostream>

Soldier::Soldier(INPC* npc)
	: NPCDecorator(npc) { }

void Soldier::Render()
{
	if (decoratedNPC)
	{
		decoratedNPC->Render();
		std::cout << "Role: Soldier" << std::endl;
	}
}