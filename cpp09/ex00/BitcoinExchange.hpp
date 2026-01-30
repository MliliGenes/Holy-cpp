#pragma once

#include <map>
#include <string>

typedef std::string string;
typedef std::map<string, double> map_data;

class BitcoinExchange {
    private:
        map_data _database;

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
        void processInputLine(const string& line) const;
        map_data::const_iterator get_targeted_date(const string& target_date) const;
};


// kill yourself you fucking retard do not ask for help