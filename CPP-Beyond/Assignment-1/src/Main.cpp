#include <iostream>
#include "Bankrekening.h"

int main()
{
	Bankrekening bankrekening;
	Transaction incomeTransaction(5000, "14/11/2023");
	Transaction computerTransaction(-1400, "25/12/2023");
	Transaction supermarketTransaction(-110, "14/11/2029");

	bankrekening += incomeTransaction;
	bankrekening += computerTransaction;
	bankrekening += supermarketTransaction;
	std::cout << bankrekening << std::endl;
	std::cin.get();
}