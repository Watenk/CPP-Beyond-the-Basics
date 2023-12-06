
#include <iostream>
#include "GridManager.h"
#include "../Interfaces/IStrategy.h"

GridManager::GridManager(Vector2Int _size, IStrategy* _strategy)
	: grid(new Cell[_size.x * _size.y]), size(_size), currentRule(_strategy)
{
	Init();
}

GridManager::~GridManager()
{
	delete[] grid;
}

Cell* GridManager::GetCell(Vector2Int _pos)
{
	if (IsOperationInBounds(_pos))
	{
		return &grid[_pos.x + (_pos.y * size.y)];
	}

	return nullptr;
}

void GridManager::SetCell(Vector2Int _pos, bool _state)
{
	if (IsOperationInBounds(_pos))
	{
		grid[_pos.x + (_pos.y * size.y)].state = _state;
	}
}

void GridManager::SetRule(IStrategy* _rule)
{
	currentRule = _rule;
}

void GridManager::Update()
{
	ExecuteRules();
	Draw();
}

void GridManager::Init()
{
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			grid[x + (y * size.y)] = Cell();
		}
	}
}

bool GridManager::IsOperationInBounds(Vector2Int _pos)
{
	if (_pos.x < 0 || _pos.x >= size.x || _pos.y < 0 || _pos.y >= size.y)
	{
		return false;
	}

	return true;
}

void GridManager::Draw()
{
	// Clear console
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			Cell* currentCell = GetCell(Vector2Int(x, y));
			if (currentCell->state == false)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << " *";
			}
		}

		std::cout << std::endl;
	}
}

void GridManager::ExecuteRules()
{
	currentRule->Execute(this);
}

Neighbours* GridManager::GetNeighbours(Vector2Int _pos)
{
	Neighbours* neighbours = new Neighbours();

	neighbours->array[0] = GetCell(Vector2Int(_pos.x, _pos.y - 1));
	neighbours->array[1] = GetCell(Vector2Int(_pos.x + 1, _pos.y - 1));
	neighbours->array[2] = GetCell(Vector2Int(_pos.x + 1, _pos.y));
	neighbours->array[3] = GetCell(Vector2Int(_pos.x + 1, _pos.y + 1));
	neighbours->array[4] = GetCell(Vector2Int(_pos.x, _pos.y + 1));
	neighbours->array[5] = GetCell(Vector2Int(_pos.x - 1, _pos.y + 1));
	neighbours->array[6] = GetCell(Vector2Int(_pos.x - 1, _pos.y));
	neighbours->array[7] = GetCell(Vector2Int(_pos.x - 1, _pos.y - 1));

	return neighbours;
}