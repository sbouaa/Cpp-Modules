#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &x)
{
    *this = x;
}

RPN &RPN::operator=(const RPN &x)
{
    if (this != &x)
        stack = x.stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &tok)
{
    return (tok == "+" || tok == "-" || tok == "*" || tok == "/");
}

void RPN::applyOp(const std::string &op)
{
    if (stack.size() < 2)
        throw std::runtime_error("Error: not enough operands.");

    double b = stack.top(); stack.pop();
    double a = stack.top(); stack.pop();
    double res = 0;

    if (op == "+")
        res = a + b;
    else if (op == "-")
        res = a - b;
    else if (op == "*")
        res = a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero.");
        res = a / b;
    }
    stack.push(res);
}

double RPN::eval(const std::string &expr)
{
    while (!stack.empty())
        stack.pop();

    std::istringstream iss(expr);
    std::string tok;

    while (iss >> tok)
    {
        if (isOperator(tok) && tok.size() == 1)
        {
            applyOp(tok);
        }
        else
        {
            // must be a single-digit, non-negative number per subject rules
            if (tok.size() != 1 || !std::isdigit(static_cast<unsigned char>(tok[0])))
                throw std::runtime_error("Error: bad token => " + tok);
            stack.push(static_cast<double>(tok[0] - '0'));
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: bad expression.");

    return stack.top();
}