#pragma once

#include <map>
#include <string>

typedef std::string string;
typedef std::map<string, double> map_data;

class BitcoinExchange {
    private:
        map_data _database;
        map_data _output;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        map_data get() const;

        bool init(const string& _db);
        void processInputFile(const string& _input);

    private:
        // validation type shiiiii
        bool isValidDate(const string& date) const ;
        bool isValidRate(const double& rate) const ;

        // parsing adn shit
        bool parseDatabase(const string& file);
        string trim(const string& str) const;
        bool addEntry(const string& date, const string& value);
        bool parseLine(const string& line,
            string& date,
            string& value);

        // idk what i should do here
        bool parseinput(const string& file);
        bool parseInputLine(const string& line,
            string& date,
            string& value);
};