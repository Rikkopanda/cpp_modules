/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:09:51 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/27 15:54:30 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

//static void	_displayTimestamp( void );

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

	_nbAccounts++;
	//this->_nbAccounts = g_nb_account + 1;
}

Account::Account( void )
{
	
}

Account::~Account( void )
{
	
}

int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

static int	getTotalAmount( void )
{
	return (0);
}
static int	getNbDeposits( void )
{

	return (0);
}
static int	getNbWithdrawals( void )
{

	return (0);
}

void Account::displayAccountsInfos( void )
{
	std::cout << "accounts: " << getNbAccounts();
	return;
}

void Account::_displayTimestamp( void )
{
	//std::cout << std::localtime();
	time_t time_ptr; 

	std::cout << std::put_time(localtime(&time_ptr), "[%Y%m%d_%H%M%S] ") << std::flush;
    // Get the localtime 
    //tm* tm_local = localtime(&time_ptr); 
	return;
}
