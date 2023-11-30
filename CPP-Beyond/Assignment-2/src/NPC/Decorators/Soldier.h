#pragma once

#include "../NPCDecorator.h"

class Soldier : public NPCDecorator
{
public:
	Soldier(INPC* npc);

	void Render() override;
};