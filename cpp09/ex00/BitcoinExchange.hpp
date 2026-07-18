#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class btc
{
    private :
        std::map<std::string, double> data;
    public :
        btc();
        btc(std::string file);
        // btc(const btc& x);
        // btc& operator=(const btc& x);
        void parsNstore(void);
        void check(std::ifstream &in);
        std::string trim(std::string x);
        int checkDate(std::string& date);
        int checkVal(std::string& val);
        int getrate(std::string &date, double &rate);
        // ~btc();
};

#endif