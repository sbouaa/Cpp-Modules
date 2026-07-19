#include "RPN.hpp"

RPN::RPN(const RPN &x)
{
    *this = x;
}

RPN& RPN::operator=(const RPN &x)
{
    if (this != &x)
        d = x.d;
    return *this;
}

void    RPN::run(std::string x)
{
    std::istringstream s(x);
    std::string val;
    while (s >> val)
    {
        if (isValidOp(val) && val.size() == 1)
            calc(val);
        else
        {
            if (val.size() != 1 || !std::isdigit(val[0]))
                throw std::runtime_error("Error: bad input.\n");
            d.push(static_cast<double>(val[0] - 48));
        }
    }
    if (d.size() != 1)
        throw std::runtime_error("Error.\n");
    std::cout<<d.top()<<std::endl;
}

void    RPN::calc(std::string op)
{
    if (d.size() < 2)
        throw std::runtime_error("Error : not enough args.\n");
    double b = d.top();
    d.pop();
    double a = d.top();
    d.pop();
    double res = 0;
    if (op == "+")
        res = a + b;
    if (op == "*")
        res = a * b;
    if (op == "-")
        res = a - b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error : division by 0 impossible.\n");
        res = a/ b;
    }
    d.push(res);
}

int RPN::isValidOp(std::string &op)
{
    if (op == "+" || op == "-" || op == "*" || op == "/")
        return 1;
    return 0;
}
