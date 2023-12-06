
#include <iostream>
#include <thread>
#include <chrono>
#include "Grid/GridManager.h"
#include "Rules/NormalRules.h"
#include "Rules/FertileRules.h"
#include "Rules/NoUnderpopRules.h"

long updateDelay = (long)100;
bool gameLoop = true;
GridManager* gridManager;

void Update()
{
	gridManager->Update();
}

int main()
{
	// Normal Rules
	gridManager = new GridManager(Vector2Int(25, 25), new NormalRules());
	
	// Fertile rules allows cells to live much more easily
	//gridManager = new GridManager(Vector2Int(25, 25), new FertileRules());

	// NoUnderpop rules: cells will not die because of under-population
	//gridManager = new GridManager(Vector2Int(25, 25), new NoUnderpopRules());

	// Use gridManager.SetRule() to change the rule at runtime

	// Glider setup
	gridManager->SetCell(Vector2Int(1, 1), true);
	gridManager->SetCell(Vector2Int(2, 2), true);
	gridManager->SetCell(Vector2Int(3, 2), true);
	gridManager->SetCell(Vector2Int(1, 3), true);
	gridManager->SetCell(Vector2Int(2, 3), true);

	// Game Loop
	while (gameLoop)
	{
		Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(updateDelay));
	}

	std::cin.get();
}