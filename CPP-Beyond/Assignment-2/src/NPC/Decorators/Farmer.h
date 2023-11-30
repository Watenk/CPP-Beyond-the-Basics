#pragma once

#include "../NPCDecorator.h"

class Farmer : public NPCDecorator
{
public:
	Farmer(INPC* npc);

	void Render() override;
};