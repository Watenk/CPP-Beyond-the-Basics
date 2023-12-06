#pragma once

#include "../Interfaces/IStrategy.h"
#include "../Grid/CellUpdate.h"

class BaseRule : public IStrategy
{
public:
	void Execute(GridManager* gridManager) override;
	virtual void ExecuteConditions(std::vector<CellUpdate>* cellUpdates, Cell* currentCell, int aliveNeighbours, Vector2Int pos) = 0;
};