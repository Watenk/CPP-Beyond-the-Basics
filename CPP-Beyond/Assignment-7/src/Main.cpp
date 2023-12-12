
#include <iostream>
#include <thread>

#include "Inventory.h"

int main()
{
	Inventory* inv = new Inventory();

	std::thread setToOneThread(&Inventory::Set, inv, 1);
	std::thread getThread(&Inventory::Get, inv, 0);
	std::thread setToTwoThread(&Inventory::Set, inv, 2);

	setToOneThread.join();
	getThread.join();
	setToTwoThread.join();

	inv->Print();

	std::cin.get();
}