#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map> //for storing date and rate pairs, better than vector
#include <string>


class BitcoinExchange
{
private:
    std::map<std::string, double> rates;

    bool isValidDate(const std::string &date) const;//check format and leap year
    bool isValidValue(const std::string &value) const;// numeric, >= 0, <= 1000
    double findRate(const std::string &date) const; //return the rate on the date or closest lower date
    double stringToDouble(const std::string &value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadRates(const std::string &filename);
    void processInput(const std::string &file);
};


#endif