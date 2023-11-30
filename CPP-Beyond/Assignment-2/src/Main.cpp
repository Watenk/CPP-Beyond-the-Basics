#include <iostream>

#include "NPC/Characters/Elf.h"
#include "NPC/Characters/Orc.h"

#include "NPC/Decorators/Farmer.h"
#include "NPC/Decorators/Soldier.h"
#include "NPC/Decorators/Shaman.h"

int main()
{
	//ElfFarmerSoldier
	INPC* elf = new Elf();
	INPC* elfFarmer = new Farmer(elf);
	INPC* elfFarmerSoldier = new Soldier(elfFarmer);
	elfFarmerSoldier->Render();

	std::cout << std::endl;

	//OrcShaman
	INPC* orc = new Orc();
	INPC* orcShaman = new Shaman(orc);
	orcShaman->Render();

	std::cout << std::endl;

	//Orc
	INPC* orc2 = new Orc();
	orc2->Render();

	std::cin.get();
}