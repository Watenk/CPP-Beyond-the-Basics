#pragma once

#include <string>

class INPC
{
public: 
	std::string name;

	virtual void Render() = 0;
};