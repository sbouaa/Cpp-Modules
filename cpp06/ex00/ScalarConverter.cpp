#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &x) { (void)x; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &x) {(void)x; return *this; }
ScalarConverter::~ScalarConverter() {}

static int isChar(const std::string& s)
{
    if (s.length() == 1 && !std::isdigit(s[0]))
        return 1;
    return 0;
}

static int isInt(const std::string& s)
{
    size_t i = 0;
    if (s.empty())
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return 0;
    while (i < s.length())
    {
        if (!std::isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}

static int isDouble(const std::string& s)
{
    int p = 0;
    size_t i = 0;
    if (s.empty())
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return 0;
    while (i < s.length())
    {
        if (s[i] == '.')
        {
            p++;
            if (p > 1)
                return 0;
        }
        else if (!std::isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}

static int isFloat(const std::string &s)
{
    int p = 0;
    size_t i = 0;
    if (s.empty() || s[s.size() - 1] != 'f')
        return 0;
    std::string a = s.substr(0, s.size() - 1);
    if (a.empty())
        return 0;
    if (a[i] == '+' || a[i] == '-')
        i++;
    if (i == a.size())
        return 0;
    // check double ff
    while (i < a.size())
    {
        if (s[i] == '.')
        {
            p++;
            if (p > 1)
                return 0;
        }
        else if (!std::isdigit(a[i]))
            return 0;
        i++;
    }
    return 1;
}

static int isPseudo(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf" ||
        s == "-inf"  || s == "+inf"  || s == "nan")
        return 1;
    return 0;
}

// static int check(const std::string& s)
// {
//     long long L = std::strtoll(s.c_str(), NULL, 10);
//     if (L > INT_MAX || L < INT_MIN)
//     {
//         std::cout<<"char : impossible\n";
//         std::cout<<"int : impossible\n";
//         std::cout<<"float : impossible\n";
//         std::cout<<"double : impossible\n";
//         return 1;
//     }
//     return 0;
// }

static void printAll(double v)
{
    if (std::isnan(v) || std::isinf(v) || v < 0 || v > 127)
        std::cout<<"char : impossible\n";
    else if (v < 32 || v == 127)
        std::cout<<"char : Non displayable\n";
    else
        std::cout<<"char : '"<<static_cast<char>(v)<<"'\n";

    if (std::isnan(v) || std::isinf(v) || v > INT_MAX || v < INT_MIN)
        std::cout<<"int : impossible\n";
    else
        std::cout<<"int : "<<static_cast<int>(v)<<std::endl;

    if (std::isnan(v))
        std::cout<<"float : nanf\n";
    else if (std::isinf(v))
    {
        if (v > 0)
            std::cout<<"float : +inff\n";
        else
            std::cout<<"float : -inff\n";
    }
    else
    {
        float f = static_cast<float>(v);
        std::cout<<"float : "<<f;
        if (f == static_cast<long long>(f))
            std::cout<<".0";
        std::cout<<"f\n";
    }

    if (std::isnan(v))
        std::cout<<"double : nan\n";
    else if (std::isinf(v))
    {
        if (v > 0)
            std::cout<<"double : +inf\n";
        else
            std::cout<<"double : -inf\n";
    }
    else
    {
        std::cout<<"double : "<<v;
        if (v == static_cast<long long>(v))
            std::cout<<".0";
        std::cout<<std::endl;
    }
}

void    ScalarConverter::convert(const std::string& literal)
{
    double v = 0;
    if (isPseudo(literal))
        v = std::strtod(literal.c_str(), NULL);
    else if (isChar(literal))
        v = literal[0];
    else if (isInt(literal))
    {
        // if (check(literal))
        //     return ;
        v = std::strtoll(literal.c_str(), NULL, 10);
    }
    else if (isDouble(literal))
        v = std::strtod(literal.c_str(), NULL);
    else if (isFloat(literal))
        v = std::strtod(literal.c_str(), NULL);
    printAll(v);
}
