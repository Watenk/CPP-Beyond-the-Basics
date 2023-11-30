#pragma once

#include "INPC.h"

class NPCDecorator : public INPC
{
protected:
	INPC* decoratedNPC;

public:
	NPCDecorator(INPC* npc);
	virtual ~NPCDecorator();

	void Render() override;
};