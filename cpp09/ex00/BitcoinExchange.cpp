#include "BitcoinExchange.hpp"

    BitcoinExchange::BitcoinExchange(){
    }

    BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
        rates = other.rates;
    }

    BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
        if (this != &other) {
            rates = other.rates;
        }
        return *this;
    }

    BitcoinExchange::~BitcoinExchange(){
    }

bool BitcoinExchange::isValidDate(const std::string &date) const{
    //leap year check
    //check format YYYY-MM-DD
}
    


bool BitcoinExchange::isValidValue(const std::string &value) const{

}




BitcoinExchange::parseDate(){

}

BitcoinExchange::parseValue(){

}
    parseValue();
    findRate();//find the rate on the closest lower date
BitcoinExchange::processInput(){

}