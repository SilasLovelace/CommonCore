/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:53:34 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/03 15:46:03 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

#define NL "\n"
#define SEMICOL ";"
#define EMPTY ""

#define M_IND "index:"
#define M_AMT "amount:"
#define M_ACC "accounts:"
#define M_DEP "deposit:"
#define M_DEPS "deposits:"
#define M_WIT "withdrawal:"
#define M_WITS "withdrawals:"
#define M_CRE "created"
#define M_CLS "closed"
#define M_TOT "total:"
#define M_P_AMT "p_amount:"
#define M_NB_DEP "nb_deposits:"
#define M_NB_WIT "nb_withdrawals:"
#define M_WIT_REF "withdrawal:refused"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* ltm = std::localtime(&now);
    
    std::cout << "[" 
              << (1900 + ltm->tm_year)
              << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon)
              << std::setfill('0') << std::setw(2) << ltm->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << ltm->tm_hour
              << std::setfill('0') << std::setw(2) << ltm->tm_min
              << std::setfill('0') << std::setw(2) << ltm->tm_sec
              << "] ";
}

void print_message(std::string message, int *num, std::string terminator) {
    std::cout   << message 
                << (num == NULL ? "" : std::to_string(*num))
                << terminator;
}
void print_line(std::string message, int *num, std::string terminator,
                std::string message2, int *num2, std::string terminator2,
                std::string message3, int *num3, std::string terminator3) {
    print_message(message, num, terminator);
    print_message(message2, num2, terminator2);
    print_message(message3, num3, terminator3);
}


Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    print_line(M_IND, &_accountIndex, SEMICOL, M_AMT, &_amount, SEMICOL, M_CRE, NULL, NL);
}

Account::~Account() {
    _displayTimestamp();
    print_line(M_IND, &_accountIndex, SEMICOL, M_AMT, &_amount, SEMICOL, M_CLS, NULL, NL);
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    print_line (M_IND, &_accountIndex, SEMICOL, M_P_AMT, &_amount, SEMICOL, M_DEP, &deposit, SEMICOL);
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    print_line(M_AMT, &_amount, SEMICOL, M_NB_DEP, &_nbDeposits, NL, EMPTY, NULL, EMPTY);
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    print_line(M_IND, &_accountIndex, SEMICOL, M_P_AMT, &_amount, SEMICOL, EMPTY, NULL, EMPTY);
    if (withdrawal > _amount) {
        std::cout << M_WIT_REF << NL;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    print_line(M_WIT, &withdrawal, SEMICOL, M_AMT, &_amount, SEMICOL, M_NB_WIT, &_nbWithdrawals, NL);
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    print_line(M_IND, (int*)(&_accountIndex), SEMICOL, M_AMT, (int*)&_amount, SEMICOL, M_NB_DEP, (int*)&_nbDeposits, SEMICOL);
    print_message(M_WITS, (int*)&_nbWithdrawals, NL);
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    print_line(M_ACC, &_nbAccounts, SEMICOL, M_TOT, &_totalAmount, SEMICOL, M_DEPS, &_totalNbDeposits, SEMICOL);
    print_message(M_WITS, &_totalNbWithdrawals, NL);
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }