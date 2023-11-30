#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
class Queue
{
public:

	void put(const T& t)
	{
		vectors.push_back(t);
		std::cout << "Added item to queue: " << t << std::endl;
	}

	T get() const
	{
		std::cout << "Getting item: " << *vectors.begin() << std::endl;
		return *vectors.begin();
	}

	std::size_t size() const
	{
		std::cout << "Size: " << vectors.size() << std::endl;
		return vectors.size();
	}

private:
	std::vector<T> vectors;
};

