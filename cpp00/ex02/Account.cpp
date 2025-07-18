/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:33:01 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/25 16:45:55 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>//for timestamps

//init static
int Account::nbAccounts = 0;
int Account::totalAmount = 0;
int Account::totalNbDeposits = 0;
int Account::totalNbWithdrawals = 0; 


void Account::displayTimestamp()
{
	//get current time
	std::time_t cur_time = std::time(nullptr);
	
	//convert localtime to readable structure
	std::tm *ltm = std::localtime(&cur_time);

	//print timestamp :[19920104_091532]
	std::cout << "[" << 1900 + ltm->tm_year 
			<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
			<< std::setfill('0') << std::setw(2) << ltm->tm_mday 
			<< "_"
			<< std::setfill('0') << std::setw(2) << ltm->tm_hour
			<< std::setfill('0') << std::setw(2) << ltm->tm_min
			<< std::setfill('0') << std::setw(2) << ltm->tm_sec
			<< "] ";
}

Account::Account(int initial_deposit): amount(initial_deposit), nbDeposits(0), nbWithdrawals(0) 
{
	//assign index with number of accounts
	accountIndex = nbAccounts;

	//update
	nbAccounts++;
	totalAmount += initial_deposit;

	//print create log : index:7;amount:16576;created
	displayTimestamp();
	std::cout << "index:" << accountIndex << ";amount:" << amount << ";created" << std::endl;

}
Account::~Account()
{
	//print log: index:0;amount:47;closed
	displayTimestamp();
	std::cout << "index:" << accountIndex << ";amount:" << amount << ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
    return nbAccounts;
}
int	Account::getTotalAmount()
{
    return totalAmount;
}
int	Account::getNbDeposits()
{
    return totalNbDeposits;
}
int	Account::getNbWithdrawals()
{
	return totalNbWithdrawals;
}
void Account::displayAccountsInfos()
{
	displayTimestamp();
	//accounts:8;total:12442;deposits:8;withdrawals:6
	std::cout << "account:" << nbAccounts << ";total:" << totalAmount << ";deposits:" << totalNbDeposits << ";withdrawals:" << totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	displayTimestamp();
	//print previous deposit log: index:0;p_amount:42;deposit:5;
	std::cout << "index:" << accountIndex << ";p_amount:" << amount << ";deposit:" << deposit;

	amount += deposit;
	totalAmount += deposit;
	nbDeposits++;
	totalNbDeposits++;
	
	//print after log: amount:47;nb_deposits:1
	std::cout << ";amount:" << amount << ";nb_deposits:" << nbDeposits << std::endl;
	
}
bool	Account::makeWithdrawal(int withdrawal)
{
	displayTimestamp();
	std::cout << "index:" << accountIndex << ";p_amount:" << amount << ";withdrawal:";
	if (amount < withdrawal)
	{
		//index:0;p_amount:47;withdrawal:
		std:: cout << "refused" << std::endl;
		return false;
	}
	
	//print log: index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

	amount -= withdrawal;
	totalAmount -= withdrawal;
	nbWithdrawals++;
	totalNbWithdrawals++;
	
	//print after log: amount:47;nb_deposits:1
	std::cout << withdrawal << ";amount:" << amount << ";nb_withdrawals:" << nbWithdrawals << std::endl;
	return true;
	
}
int		Account::checkAmount() const
{
	return amount;
}

void	Account::displayStatus() const
{
	displayTimestamp();
    std::cout << "index:" << accountIndex 
            << ";amount:" << amount 
            << ";deposits:" << nbDeposits 
            << ";withdrawals:" << nbWithdrawals
            << std::endl;
}