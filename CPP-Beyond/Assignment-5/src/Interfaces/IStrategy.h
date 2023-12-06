#pragma once

#include "../Grid/GridManager.h"

class IStrategy
{
public:
	virtual void Execute(GridManager* gridManager) = 0;
};