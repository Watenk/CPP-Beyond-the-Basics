#pragma once

#include <vector>
#include <mutex>

class Inventory
{
public:
	Inventory();
	int Get(int index) const;
	void Set(int value);
	void Print() const;

private:
	std::vector<int> inventoryVector;
	std::mutex inventoryMutex;
};