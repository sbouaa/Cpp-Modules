#include "Account.hpp"

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created\n";
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount
        <<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"
    <<_nbWithdrawals<<std::endl;
}

void    Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:"
    << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    int p_amount = _amount;
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:refused\n";
        return false;
    }
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:"<<withdrawal
        <<";amount:"<<_amount<<";nb_withdrawals:"<<++_nbWithdrawals<<std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
    std::time_t time = std::time(NULL);
    std::tm *ptr = std::localtime(&time);
    std::cout << "[" << ptr->tm_year + 1900 << ptr->tm_mon + 1 << ptr->tm_mday << "_";
    if (ptr->tm_hour < 10)
        std::cout<<"0";
    std::cout<<ptr->tm_hour;
    if (ptr->tm_min < 10)
        std::cout<<"0";
    std::cout<<ptr->tm_min;
    if (ptr->tm_sec < 10)
        std::cout<<"0";
    std::cout<<ptr->tm_sec<<"] ";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed\n";
}