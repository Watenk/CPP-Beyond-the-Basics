#include "Farmer.h"

#include <iostream>

Farmer::Farmer(INPC* npc)
	: NPCDecorator(npc) { }

void Farmer::Render()
{
	if (decoratedNPC)
	{
		decoratedNPC->Render();
		std::cout << "Role: Farmer" << std::endl;
	}
}