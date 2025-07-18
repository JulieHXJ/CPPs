// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;//Creates an alias

	static int	getNbAccounts(void);
	static int	getTotalAmount(void);
	static int	getNbDeposits(void);
	static int	getNbWithdrawals(void);
	static void	displayAccountsInfos(void);//show information about all accounts

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );//Adds amount to the account balance
	bool	makeWithdrawal( int withdrawal );//Tries to withdraw the specified amount.
	int		checkAmount( void ) const;//Returns the current balance of the account
	void	displayStatus( void ) const;//display balance and the number of deposits and withdrawals


private:

	//Variables shared scross all Accounts, need to be updated whenever an account is created.
	static int	nbAccounts;//total number of accounts.
	static int	totalAmount;//total amount in all accounts.
	static int	totalNbDeposits;//total number of deposits.
	static int	totalNbWithdrawals;//total number of withdrawals.

	static void	displayTimestamp( void );

	// Variables unique to each Account, need to be initialized when a new account is created.
	int				accountIndex;
	int				amount;//curren balance
	int				nbDeposits; //The number of deposits made to account
	int				nbWithdrawals;//The number of withdrawals made from the account

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
