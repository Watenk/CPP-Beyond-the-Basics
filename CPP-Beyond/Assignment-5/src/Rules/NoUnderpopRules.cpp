
#include "NoUnderpopRules.h"

void NoUnderpopRules::ExecuteConditions(std::vector<CellUpdate>* cellUpdates, Cell* currentCell, int aliveNeighbours, Vector2Int pos)
{
	// If currentCell is alive
	if (currentCell->state == true)
	{
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