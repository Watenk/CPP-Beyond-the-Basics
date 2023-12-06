
#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
	Zero();
}

Vector2Int::Vector2Int(int _x, int _y)
	: x(_x), y(_y) { }

void Vector2Int::Zero()
{
	x = 0;
	y = 0;
}