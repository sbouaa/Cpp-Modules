#include "BitcoinExchange.hpp"

btc::btc() {}

btc::btc(std::string file)
{
    std::ifstream in(file.c_str());
    if (!in.is_open())
        throw std::runtime_error("Error : could not open file.\n");
    parsNstore();
    check(in);
}

void    btc::check(std::ifstream &in)
{
    std::string line;
    std::getline(in, line);
    while (getline(in, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout<<"Error : bad input => "<<line<<std::endl;
            continue;
        }
        std::string d = trim(line.substr(0, pos));
        std::string v = trim(line.substr(pos + 1));
        if (!checkDate(d))
        {
            std::cout<<"Error : bad input => "<<d<<std::endl;
            continue;
        }
        if (!checkVal(v))
            continue;
        double rate;
        if (!getrate(d, rate))
        {
            std::cout<<"Error : no date.\n";
            continue;
        }
        double val = std::strtod(v.c_str(), NULL);
        std::cout<<d<<" => "<<val<<" = "<<val * rate<<std::endl;
    }
}

std::string btc::trim(std::string s)
{
    size_t st = s.find_first_not_of(" \t");
    if (st == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t");
    if (end == std::string::npos)
        return "";
    return s.substr(st, end - st + 1);
}

int btc::checkDate(std::string& date)
{
    if (date.empty())
        return 0;
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return 0;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7) 
            continue;
        if (!std::isdigit(date[i]))
            return 0;
    }
    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    if ((m < 1 || m > 12) || d < 1)
        return 0;
    int max = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        max = 30;
    else if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            max = 29;
        else
            max = 28;
    }
    return d <= max;
}

int btc::checkVal(std::string& val)
{
    if (val.empty())
    {
        std::cout<<"Error : empty value.\n";
        return 0;
    }
    char *end;
    double v = std::strtod(val.c_str(), &end);
    if (*end != '\0')
    {
        std::cout<<"Error : bad input.\n";
        return 0;
    }
    if (v > 1000)
    {
        std::cout<<"Error : too large number.\n";
        return 0;
    }
    if (v < 0)
    {
        std::cout<<"Error : not a positive number.\n";
        return 0;
    }
    return 1;
}

int btc::getrate(std::string &date, double &rate)
{
    std::map<std::string, double>::iterator i = data.lower_bound(date);
    if (i != data.end() && i->first == date)
    {
        rate = i->second;
        return 1;
    }
    if (i == data.begin())
        return 0;
    --i;
    rate = i->second;
    return 1;
}

void    btc::parsNstore(void)
{
    std::ifstream in("data.csv");
    if (!in.is_open())
        throw std::runtime_error("Error : could not open file.\n");
    std::string d;
    std::string p;
    std::getline(in, d);
    while (std::getline(in, d, ','))
    {
        std::getline(in, p);
        double s = std::strtod(p.c_str(), NULL);
        data[d] = s;
    }
    in.close();
}