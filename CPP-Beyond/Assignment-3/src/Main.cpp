#include <iostream>

#include "Queue.h"
#include "Algorithms.h"

#include <string>

int main()
{
	//Template Function:
	Algorithms algorithms;
	std::cout << "Template Functions: " << std::endl;

	//Float
	std::vector<float> floatVector = { 1.1f, 6.2f, 2.6f, 3.5f };
	algorithms.print<float>(floatVector);
	algorithms.sort<float>(floatVector);
	algorithms.print<float>(floatVector);

	//String
	std::vector<std::string> stringVector = { "B", "A", "H", "Z", "P" };
	algorithms.print<std::string>(stringVector);
	algorithms.sort<std::string>(stringVector);
	algorithms.print<std::string>(stringVector);

	std::cout << std::endl;

	//Template Class:
	std::cout << "Template Classes: " << std::endl;
	//Float
	Queue<float> floatSort;

	floatSort.put(3);
	floatSort.put(6);
	floatSort.size();
	floatSort.get();

	std::cout << std::endl;

	//String
	Queue<std::string> stringSort;

	stringSort.put("Test");
	stringSort.size();

	std::cin.get();
}