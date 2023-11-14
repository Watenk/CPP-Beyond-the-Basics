#pragma once
#include <vector>
#include <iostream>
#include "Transaction.h"

class Bankrekening
{
public:
	Bankrekening();

	Bankrekening operator+=(const Transaction& _transaction);
	friend std::ostream& operator<<(std::ostream& _os, const Bankrekening& _bankrekening);

private:
	int GetMoney() const;
	bool ChangeMoney(const Transaction& _transaction);
	void SaveTransaction(const Transaction& _transaction);

	int balance;
	std::vector<Transaction> transactionHistory;
};