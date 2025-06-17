/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:01:46 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/12 17:04:14 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// Initialiser les données de account

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Faire un constructeur

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

// Faire un destructeur
// Exécution quand un compte est détruit. Message de fermeture du comte et solde

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

// Fonction makedeposit
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << endl;
}

// fonction makewithdrawal
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount;

	if (withdrawal > _amount) {
		cout << ";withdrawal:refused" << endl;
		return (false);
	}
	
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << endl;
	return (true);
}

int	Account::checkAmount() const {
	return (_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << endl;
}

void Account::_displayTimestamp()
{
	time_t now = time(nullptr);
	tm *ptm = localtime(&now);
	cout << "[" << put_time(ptm, "%Y%m%d_%H%M%S") << "] ";
}
