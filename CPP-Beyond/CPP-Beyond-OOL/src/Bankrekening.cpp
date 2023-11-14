#include "Bankrekening.h"

Bankrekening::Bankrekening() 
	: balance(0) { }

int Bankrekening::GetMoney() const
{
	return balance;
}

bool Bankrekening::ChangeMoney(const Transaction& _transaction)
{
	if (_transaction.Amount < 0)
	{
		if (balance - _transaction.Amount >= 0)
		{
			balance += _transaction.Amount;
			return true;
		}
	}
	else
	{
		balance += _transaction.Amount;
		return true;
	}

	return false;
}

void Bankrekening::SaveTransaction(const Transaction& _transaction)
{
	transactionHistory.push_back(_transaction);
}

Bankrekening Bankrekening::operator+=(const Transaction& _transaction)
{
	if (ChangeMoney(_transaction))
	{
		SaveTransaction(_transaction);
	}
	else
	{
		std::cout << "Not Enough Money on bankrekening for transaction" << std::endl;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& _os, const Bankrekening& _bankrekening)
{
	_os << "Current Balance: ";
	_os << _bankrekening.GetMoney() << std::endl;
	_os << std::endl;

	_os << "Transaction History: " << std::endl;
	for (int i = 0; i < _bankrekening.transactionHistory.size(); i++) 
	{ 
		_os << _bankrekening.transactionHistory[i].Date << std::endl;
		_os << _bankrekening.transactionHistory[i].Amount << std::endl;
		_os << std::endl;
	}

	return _os;
}