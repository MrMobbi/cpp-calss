
#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//	### Public Function ###

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "nb_deposit:" << this->_nbDeposits << ";";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (this->_amount >= withdrawal)
	{
		std::cout << withdrawal << ";";
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
		std::cout << std::endl;
		return (false);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals" << this->_nbWithdrawals << ";";
	std::cout << std::endl;
}

//	### Constructor and Destructor ###

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account(void)
{
	return ;
}

Account::~Account(void)
{
	_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

//	### Private Function ###

void Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*time = localtime(&now);

	std::cout << "[";
	std::cout << 1900 + time->tm_year; // +1900 because it's years since 1900
	if (time->tm_mon + 1 < 10) // +1 because it's month grom 0 to 11
		std::cout << "0" << 1 + time->tm_mon;
	else
		std::cout << 1 + time->tm_mon;
	if (time->tm_mday < 10)
		std::cout << "0" << time->tm_mday;
	else
		std::cout << time->tm_mday;
	std::cout << "_";
	if (time->tm_hour == 0 || time->tm_hour == 24)
		std::cout << "00";
	else if (time->tm_hour < 10)
		std::cout << "0" << time->tm_hour;
	else
		std::cout << time->tm_hour;
	if (time->tm_min < 10)
		std::cout << "0" << time->tm_min;
	else
		std::cout << time->tm_min;
	if (time->tm_sec < 10)
		std::cout << "0" << time->tm_sec;
	else
		std::cout << time->tm_sec;
	std::cout << "] ";
}
