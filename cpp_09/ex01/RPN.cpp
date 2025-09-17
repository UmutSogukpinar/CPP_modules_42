#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

// =========================  Orthodox Canonical Form =========================

RPN::RPN() {}

RPN::RPN(std::queue<std::string> strQueue) : strQueue_(strQueue)
{
    processStack();
}

RPN::RPN(const RPN &other) : strQueue_(other.strQueue_), numStack_(other.numStack_) {}

RPN::~RPN() {}

RPN & RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->numStack_ = other.numStack_;
        this->strQueue_ = other.strQueue_;
    }
    return (*this);
}

// ========================= RPN Member Functions =========================

static bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::processStack()
{
    std::string arg;

    while (!strQueue_.empty())
    {
        arg = strQueue_.front();
        strQueue_.pop();

        bool isArgDigit = (arg.size() == 1 && std::isdigit(static_cast<unsigned char>(arg[0])));
        bool isArgOperator = (arg.size() == 1 && isOperator(arg[0]));

        if (!isArgDigit && !isArgOperator)
            throw std::invalid_argument("Invalid token: " + arg);

        if (isArgDigit)
        {
            int number = arg[0] - '0';
            numStack_.push(number);
        }
        else if (isArgOperator)
            processCalculations(arg[0]);
    }

    if (numStack_.size() != 1)
        throw std::logic_error("Invalid syntax: leftover numbers in stack!");

    std::cout << numStack_.top() << std::endl;
}

void RPN::processCalculations(char opt)
{
    if (numStack_.size() < 2)
        throw std::logic_error("Not enough operands for operator " + std::string(1, opt));

    int num1 = numStack_.top();
	numStack_.pop();

    int num2 = numStack_.top();
	numStack_.pop();

    int result = 0;
    switch (opt)
    {
        case '+':
			result = num2 + num1; break;
        case '-':
			result = num2 - num1; break;
        case '*':
			result = num2 * num1; break;
        case '/':
            if (num1 == 0)
                throw std::runtime_error("Division by zero!");
            result = num2 / num1;
            break;
    }

    numStack_.push(result);
}
