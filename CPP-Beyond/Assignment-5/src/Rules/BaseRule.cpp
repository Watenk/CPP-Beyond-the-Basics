
#include <vector>
#include "BaseRule.h"
#include "../Grid/Cell.h"

void BaseRule::Execute(GridManager* gridManager)
{
	std::vector<CellUpdate> cellUpdates;

	for (int y = 0; y < gridManager->size.y; y++)
	{
		for (int x = 0; x < gridManager->size.x; x++)
		{
			Cell* currentCell = gridManager->GetCell(Vector2Int(x, y));
			Cell** neighbours = gridManager->GetNeighbours(Vector2Int(x, y))->array;
			int aliveNeighbours = 0;

			// Count alive neighbours
			for (int i = 0; i < 8; i++)
			{
				Cell* currentNeighbour = neighbours[i];

				if (currentNeighbour != nullptr)
				{
					if (currentNeighbour->state == true)
					{
						aliveNeighbours++;
					}
				}
			}

			ExecuteConditions(&cellUpdates, currentCell, aliveNeighbours, Vector2Int(x, y));

			delete[] neighbours;
		}
	}

	// Execute cellUpdates
	for (CellUpdate& cellUpdate : cellUpdates)
	{
		gridManager->SetCell(cellUpdate.pos, cellUpdate.state);
	}
}