#pragma once

#include <string>

const struct Transaction
{
public:
	Transaction(int _amount, std::string _date);
	const int Amount;
	const std::string Date;
};