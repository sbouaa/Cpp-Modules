#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &x) { (void)x; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &x) {(void)x; return *this; }
ScalarConverter::~ScalarConverter() {}

static int isChar(const std::string& s)
{
    if (s.length() == 1 && !std::isdigit(s[0]))
        return (1);
    return 0;
}

static int isInt(const std::string& s)
{
    size_t i = 0;
    if (s.empty())
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (i < s.length())
    {
        if (!std::isdigit(s[i]))
            return 0;
        i++;
    }
    long L = std::strtol(s.c_str(), NULL, 10);
    if (L > INT_MAX || L < INT_MIN)
        return 0;
    return 1;
}

static int isDouble(const std::string& s)
{
    int p = 0, d = 0;
    size_t i = 0;
    if (s.empty())
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (i < s.length())
    {
        if (s[i] == '.')
            p++;
        else if (std::isdigit(s[i]))
            d = 1;
        else
            return 0;
        i++;
    }
    return (p <= 1 && d);
}

static int isFloat(const std::string &s)
{
    int p = 0, d = 0;
    size_t i = 0;
    if (s.empty() || s[s.size() - 1] != 'f')
        return 0;
    std::string a = s.substr(0, s.size() - 1);
    if (a.empty())
        return 0;
    if (a[i] == '+' || a[i] == '-')
        i++;
    while (i < a.size())
    {
        if (a[i] == '.')
            p++;
        else if (std::isdigit(a[i]))
            d = 1;
        else
            return 0;
        i++;
    }
    return (p == 1 && d);
}

static int isNan(const std::string &s)
{
    if (s == "nan" || s == "nanf")
        return 1;
    return 0;
}

static int isInf(const std::string &s)
{
    if (s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
        return 1;
    return 0;
}

static void check(void)
{
    std::cout<<"char : impossible\n";
    std::cout<<"int : impossible\n";
    std::cout<<"float : impossible\n";
    std::cout<<"double : impossible\n";
}

static void printAll(double v, const std::string &s)
{
    if (isNan(s) || isInf(s) || v < 0 || v > 127)
        std::cout<<"char : impossible\n";
    else if (v < 32 || v == 127)
        std::cout<<"char : Non displayable\n";
    else
        std::cout<<"char : '"<<static_cast<char>(v)<<"'\n";

    if (isNan(s) || isInf(s) || v > INT_MAX || v < INT_MIN)
        std::cout<<"int : impossible\n";
    else
        std::cout<<"int : "<<static_cast<int>(v)<<std::endl;

    if (isNan(s))
        std::cout<<"float : nanf\n";
    else if (isInf(s))
    {
        if (v > 0)
            std::cout<<"float : +inff\n";
        else
            std::cout<<"float : -inff\n";
    }
    else
    {
        float f = static_cast<float>(v);
        std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<f;
        std::cout<<"f\n";
    }

    if (isNan(s))
        std::cout<<"double : nan\n";
    else if (isInf(s))
    {
        if (v > 0)
            std::cout<<"double : +inf\n";
        else
            std::cout<<"double : -inf\n";
    }
    else
    {
        std::cout<<"double : "<<std::fixed<<std::setprecision(1)<<v;
        std::cout<<std::endl;
    }
}

void    ScalarConverter::convert(const std::string& str)
{
    double v = 0;
    if (isNan(str) || isInf(str))
        v = std::strtod(str.c_str(), NULL);
    else if (isChar(str))
        v = str[0];
    else if (isInt(str))
        v = std::strtol(str.c_str(), NULL, 10);
    else if (isDouble(str))
        v = std::strtod(str.c_str(), NULL);
    else if (isFloat(str))
        v = std::strtod(str.c_str(), NULL);
    else
        return (check());
    printAll(v, str);
}
