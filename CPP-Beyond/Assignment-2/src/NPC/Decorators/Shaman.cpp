#include "Shaman.h"

#include <iostream>

Shaman::Shaman(INPC* npc)
	: NPCDecorator(npc) { }

void Shaman::Render()
{
	if (decoratedNPC)
	{
		decoratedNPC->Render();
		std::cout << "Role: Shaman" << std::endl;
	}
}