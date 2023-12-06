#pragma once

#include <vector>
#include "../Grid/CellUpdate.h"
#include "BaseRule.h"

class NormalRules : public BaseRule
{
	void ExecuteConditions(std::vector<CellUpdate>* cellUpdates, Cell* currentCell, int aliveNeighbours, Vector2Int pos) override;
};