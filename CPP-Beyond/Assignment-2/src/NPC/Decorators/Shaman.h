#pragma once

#include "../NPCDecorator.h"

class Shaman : public NPCDecorator
{
public: 
	Shaman(INPC* npc);

	void Render() override;
};