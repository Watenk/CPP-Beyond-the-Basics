#pragma once

#include "../Vector2Int.h"
#include "Cell.h"
#include "Neighbours.h"
class IStrategy;

class GridManager
{
public:
	Vector2Int size;

	GridManager(Vector2Int _size, IStrategy* _rule);
	~GridManager();
	Cell* GetCell(Vector2Int _pos);
	Neighbours* GetNeighbours(Vector2Int _pos);
	void SetCell(Vector2Int _pos, bool _state);
	void SetRule(IStrategy* _rule);
	void Update();

private:
	Cell* grid;
	IStrategy* currentRule;

	void Init();
	bool IsOperationInBounds(Vector2Int _pos);
	void Draw();
	void ExecuteRules();
};