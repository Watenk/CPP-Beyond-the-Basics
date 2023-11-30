#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Algorithms
{
public:
	template <typename T>
	void sort(std::vector<T>& currentVector)
	{
		std::cout << "Sorting..." << std::endl;
		std::sort(currentVector.begin(), currentVector.end());
	}

	template <typename T>
	void print(std::vector<T>& currentVector)
	{
		std::cout << "Printing Vector: " << std::endl;
		typename std::vector<T>::const_iterator i = currentVector.begin();
		while (i != currentVector.end())
		{
			std::cout << *i << std::endl;
			i++;
		}
	}
};