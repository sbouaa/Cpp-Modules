#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& x);
        ScalarConverter& operator=(const ScalarConverter& x);
        ~ScalarConverter();
    public :
        static void convert(const std::string& str);
};

#endif