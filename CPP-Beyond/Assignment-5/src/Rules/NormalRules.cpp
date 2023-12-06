
#include "NormalRules.h"

void NormalRules::ExecuteConditions(std::vector<CellUpdate>* cellUpdates, Cell* currentCell, int aliveNeighbours, Vector2Int pos)
{
	// If currentCell is alive
	if (currentCell->state == true)
	{
		// Underpopulation
		if (aliveNeighbours < 2)
		{
			cellUpdates->push_back(CellUpdate(Vector2Int(pos.x, pos.y), false));
		}

		// Overpopulation
		if (aliveNeighbours > 3)
		{
			cellUpdates->push_back(CellUpdate(Vector2Int(pos.x, pos.y), false));
		}
	}
	else // If currentCell is dead
	{
		if (aliveNeighbours == 3)
		{
			cellUpdates->push_back(CellUpdate(Vector2Int(pos.x, pos.y), true));
		}
	}
}