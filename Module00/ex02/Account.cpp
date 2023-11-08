/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:23:19 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/08 15:46:33 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// Inizializzazione variabili
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Timestamp
void	Account::_displayTimestamp() {
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') << "["
				<< 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<< std::setw(2) << std::localtime(&result)->tm_mday
				<< "_"
				<< std::setw(2) << std::localtime(&result)->tm_hour
				<< std::setw(2) << std::localtime(&result)->tm_min
				<< std::setw(2) << std::localtime(&result)->tm_sec
				<< "] " << std::flush;
}

// Creazione conto
Account::Account(int start_amount) {
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = start_amount;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

// Cancellazione conto
Account::~Account(void) {
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

// Definizione dei metodi getter
int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

// Mostra rapporto generale
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl; 
}

// Deposito
void	Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";" << std::flush;
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";"
                << "amount:" << _amount << ";"
                << "nb_deposits:" << _nbDeposits << std::endl;
}

// Ritiro
bool	Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:" << std::flush;
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";" << std::flush;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

// Controllo saldo disponibile
int	Account::checkAmount(void) const {
	return _amount;
}

// Mostra info conto
void	Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
            	<< "amount:" << _amount << ";"
            	<< "deposits:" << _nbDeposits << ";"
            	<< "withdrawals:" << _nbWithdrawals << std::endl;
}