#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp( void ) {

    std::time_t now = std::time(0);

    std::tm* localTime = std::localtime(&now);

    int year   = localTime->tm_year + 1900; // tm_year is years since 1900
    int month  = localTime->tm_mon + 1;     // tm_mon is 0-based
    int day    = localTime->tm_mday;
    int hour   = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    std::cout << "["
        << year
        << std::setw(2) << std::setfill('0') << month
        << std::setw(2) << std::setfill('0') << day
        << "_"
        << std::setw(2) << std::setfill('0') << hour
        << std::setw(2) << std::setfill('0') << minute
        << std::setw(2) << std::setfill('0') << second
        << "]";
}

static void accountAction(int index, int amount, const std::string msg) {
    std::cout << " index:" << index 
            << ";amount:" << amount 
            << ";" << msg << std::endl; 
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbDeposits = _nbWithdrawals = 0;

    _displayTimestamp();
    accountAction(_accountIndex, _amount, "created");
}

Account::~Account( void ) {
    _displayTimestamp();
    accountAction(_accountIndex, _amount, "closed");
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
   return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {
   _displayTimestamp();
   std::cout << " accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
            << ";amount:" << _amount
            <<  ";deposits:"   << _nbDeposits
            << ";withdrawals" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();

    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout
        << " index:" << _accountIndex
        << ";p_amount:" << p_amount
        << ";deposit:" << deposit
        << ";amount:" << _amount
        << ";nb_deposits:" << _nbDeposits
        << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();

    int previous_amount = _amount;

    if (_amount < withdrawal) {
        std::cout
            << " index:" << _accountIndex
            << ";p_amount:" << previous_amount
            << ";withdrawal:refused"
            << std::endl;
        return false;
    } else {
        _amount -= withdrawal;
        _nbWithdrawals++;

        _totalNbWithdrawals ++;
        _totalAmount -= withdrawal;
        std::cout
            << " index:" << _accountIndex
            << ";p_amount:" << previous_amount
            << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;
        return true;
    }
}
