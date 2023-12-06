#pragma once

#include "../Vector2Int.h"

struct CellUpdate
{
public:
	Vector2Int pos;
	bool state;

	CellUpdate(Vector2Int _pos, bool _state);
};