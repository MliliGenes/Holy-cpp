#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return  *this;
    _database = other._database;

    return *this;
}

bool BitcoinExchange::init(const string& _db) {
    return parseDatabase(_db);
}

void BitcoinExchange::processInputFile(const string& _input) {
    std::ifstream input_file(_input.c_str());
    if (!input_file.is_open()) {
        std::cerr << "" << std::endl;
    }
}

map_data BitcoinExchange::get() const {
    return _database;
}

string BitcoinExchange::trim(const string& str) const {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));
    
    int year, month, day;
    if (!(yearStream >> year) || 
        !(monthStream >> month) || 
        !(dayStream >> day)) {
        return false;
    }
    
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 
                        31, 31, 30, 31, 30, 31};
    
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || 
                (year % 400 == 0);
    if (month == 2 && isLeap) {
        daysInMonth[1] = 29;
    }
    
    if (day > daysInMonth[month - 1]) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidRate(const double& rate) const {
    if (rate < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::parseDatabase(const string& file) {
    std::ifstream db_file(file.c_str());
    if (!db_file.is_open()) {
        std::cerr << "Error: can't open the data.csv file." << std::endl;
        return false;
    }

    string line, date, value;
    std::getline(db_file, line);
    
    while (std::getline(db_file, line)) {
        if (line.empty())
            continue;
        if (!parseLine(line, date, value))
            return false;
        if (!addEntry(date, value))
            return false;
    }

    return true;
}

bool BitcoinExchange::parseLine(const string& line, string& date, string& value) {
    size_t pos = line.find(",");
    if (pos == string::npos) {
        std::cerr << "unvalid format: no ," << std::endl;
        return false;
    }
    date = trim(line.substr(0, pos));
    value = trim(line.substr(pos + 1));
    return true;
}

bool BitcoinExchange::addEntry(const string& date, const string& value) {
    double rate;

    std::istringstream iss(value);
    if (!(iss >> rate) || !iss.eof())
        return false;

    if (!isValidDate(date) || !isValidRate(rate))
        return false;

    _database[date] = rate;
    return true;
}