#include "Account.hpp"
#include <iostream>

// ==============  Static variables ==================

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ============= Getters ===================

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

// ============= Constructor ===================

Account::Account()
	: _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	(_nbAccounts)++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created"
				<< "\n";
}

// ============= Destructor ===================

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed"
				<< "\n";
}

// ============= Display functions ===================

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< "\n";
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< "\n";
}

void Account::_displayTimestamp()
{
	time_t		now;
	struct tm	*dt;

	now = time(NULL);
	dt = localtime(&now);
	std::cout << "[" << (dt->tm_year + 1900);

	if (dt->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (dt->tm_mon + 1);

	if (dt->tm_mday < 10)
		std::cout << "0";
	std::cout << dt->tm_mday;

	std::cout << "_";

	if (dt->tm_hour < 10)
		std::cout << "0";
	std::cout << dt->tm_hour;

	if (dt->tm_min < 10)
		std::cout << "0";
	std::cout << dt->tm_min;

	if (dt->tm_sec < 10)
		std::cout << "0";
	std::cout << dt->tm_sec << "]";
}

// ============= Deposit and withdrawal functions ===================

int Account::checkAmount() const
{
	return (_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	newAmount;

	newAmount = _amount - withdrawal;
	_displayTimestamp();
	if (newAmount < 0)
	{
		std::cout << " index:" << _accountIndex
					<< ";p_amount:" << _amount
					<< ";withdrawal:refused"
					<< "\n";
		return (false);
	}
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << newAmount
				<< ";nb_withdrawals:" << _nbWithdrawals + 1
				<< "\n";
	_amount = newAmount;
	(_nbWithdrawals)++;
	_totalAmount -= withdrawal;
	(_totalNbWithdrawals)++;
	return (true);
}

void Account::makeDeposit(int deposit)
{
	int	newAmount;

	_displayTimestamp();
	newAmount = _amount + deposit;
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << newAmount
				<< ";nb_deposits:" << _nbDeposits + 1
				<< "\n";
	_amount = newAmount;
	(_nbDeposits)++;
	(_totalNbDeposits)++;
	_totalAmount += deposit;
}
