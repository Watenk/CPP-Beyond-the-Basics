#include "NPCDecorator.h"

NPCDecorator::NPCDecorator(INPC* npc)
	: decoratedNPC(npc) { }

NPCDecorator::~NPCDecorator()
{
	delete decoratedNPC;
}

void NPCDecorator::Render()
{
	if (decoratedNPC)
	{
		decoratedNPC->Render();
	}
}