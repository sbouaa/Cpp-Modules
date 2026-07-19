#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>


class RPN
{
    private :
        std::stack<double> d;
    public :
        RPN();
        RPN(const RPN &x);
        RPN(std::string &x);
        RPN& operator=(const RPN &x);
        void    run(std::string x);
        int     isValidOp(std::string &op);
        void    calc(std::string op);
        ~RPN();
};

#endif