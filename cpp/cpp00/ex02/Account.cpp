/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:26:08 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 15:51:16 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cstdio>
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
    std::time_t	rawtime;
    std::tm*	timeinfo;
	char		buffer[64];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(buffer,80,"%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
	return ;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();

	std::cout <<
	"index:" <<
	Account::_nbAccounts <<
	";amount:" <<
	this->_amount <<
	";created" <<
	std::endl;

	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	
	std::cout <<
	"index:" <<
	this->_accountIndex <<
	";amount:" <<
	this->_amount <<
	";closed" <<
	std::endl;

	return ;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout <<
	"accounts:" <<
	Account::_nbAccounts <<
	";total:" <<
	Account::_totalAmount <<
	";deposits:" <<
	Account::_totalNbDeposits <<
	";withdrawals:" <<
	Account::_totalNbWithdrawals <<
	std::endl;
	
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout <<
	"index:" <<
	this->_accountIndex <<
	";p_amount:" <<
	this->_amount <<
	";deposit:" <<
	deposit;

	this->_amount += deposit;
	this->_nbDeposits += 1;

	std::cout <<
	";amount:" <<
	this->_amount <<
	";nb_deposits:" <<
	this->_nbDeposits <<
	std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout <<
	"index:" <<
	this->_accountIndex <<
	";p_amount:" <<
	this->_amount <<
	";withdrawal:";

	if (withdrawal > this->_amount)
	{
		std::cout <<
		"refused";
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		std::cout <<
		withdrawal <<
		";amount:" <<
		this->_amount <<
		";nb_withdrawals:" <<
		this->_nbWithdrawals;
	}
	std::cout << std::endl;

	return (true);
}

int	Account::checkAmount(void) const
{
	std::cout << "checkAmount\n";
	return (0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout <<
	"index:" <<
	this->_accountIndex <<
	";amount:" <<
	this->_amount <<
	";deposits:" <<
	this->_nbDeposits <<
	";withdrawals:" <<
	this->_nbWithdrawals <<
	std::endl;

	return ;
}