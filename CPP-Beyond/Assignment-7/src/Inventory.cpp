
#include <iostream>

#include "Inventory.h"

Inventory::Inventory()
{
	for (int i = 0; i < 10; i++)
	{
		inventoryVector.push_back(0);
	}
}

void Inventory::Set(int value)
{
	for (int i = 0; i < 10; i++)
	{
		std::lock_guard<std::mutex> lock(inventoryMutex);
		inventoryVector[i] = value;
	}
}

int Inventory::Get(int index) const
{
	return inventoryVector[index];
}

void Inventory::Print() const
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Index " << i << ": " << inventoryVector[i] << std::endl;
	}
}