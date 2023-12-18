#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
  time_t ttime = time(0);
  tm *local_time = localtime(&ttime);

  std::cout << "[" << 1900 + local_time->tm_year;
  std::cout << 1 + local_time->tm_mon;
  std::cout << local_time->tm_mday;
  std::cout << "_" << local_time->tm_hour;
  std::cout << local_time->tm_min;
  std::cout << local_time->tm_sec << "] ";
}

Account::Account(int initial_dep) : _amount(initial_dep) {
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  this->_totalAmount += this->_amount;
  this->_accountIndex = this->_nbAccounts;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;

  this->_nbAccounts++;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int Account::checkAmount(void) const { return _amount; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  _nbDeposits++;
  _totalNbDeposits++;
  _totalAmount += deposit;
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";";
  _amount += deposit;
  std::cout << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposit:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:";
  if (withdrawal > checkAmount()) {
    std::cout << "refused" << std::endl;
    return false;
  }
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  _totalAmount -= withdrawal;
  _amount -= withdrawal;
  std::cout << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}
