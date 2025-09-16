#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>

// ============================== BitcoinExchange Class ==============================

// ============= Constructors and Destructor =============

// Default Constructor
BitcoinExchange::BitcoinExchange() : file_(NULL) {} 

// Parameterized Constructor
BitcoinExchange::BitcoinExchange(std::ifstream *file) 
    : file_(file)
{
    if (!file_ || !file_->is_open())
    {
        throw std::invalid_argument("File is not open");
    }

    
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :    
    file_(other.file_), exchangeRates_(other.exchangeRates_) {}

// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        file_ = other.file_;
        exchangeRates_ = other.exchangeRates_;
    }

    return (*this);
}


// ============================== Date Class ==============================


// ============= Constructors and Destructor =============

// Default Constructor
BitcoinExchange::Date::Date() {}

// Parameterized Constructor
BitcoinExchange::Date::Date(std::string dateStr, float value_)
    : dateStr_(dateStr), value_(0.0)
{
    // Parse the date string in "YYYY-MM-DD" format
    parseDate(dateStr);

    // Validate the date
    if (!isValid())
    {
        throw std::invalid_argument("Invalid date");
    }

    
}

// Copy Constructor
BitcoinExchange::Date::Date(const Date& other) :
    year_(other.year_), month_(other.month_), day_(other.day_) {}

// Destructor
BitcoinExchange::Date::~Date() {}

// Assignment Operator
BitcoinExchange::Date& BitcoinExchange::Date::operator=(const Date& other)
{
    if (this != &other)
    {
        year_ = other.year_;
        month_ = other.month_;
        day_ = other.day_;
    }

    return (*this);
}

// ============= Getters =============

int BitcoinExchange::Date::getYear() const
{
    return (year_);
}

int BitcoinExchange::Date::getMonth() const
{
    return (month_);
}

int BitcoinExchange::Date::getDay() const
{
    return (day_);
}

std::string &BitcoinExchange::Date::getDateStr() const
{
    return (const_cast<std::string&>(dateStr_));
}

float BitcoinExchange::Date::getValue() const
{
    return (value_);
}

// ============= Setters =============

void BitcoinExchange::Date::setYear(int year)
{
    year_ = year;
}

void BitcoinExchange::Date::setMonth(int month)
{
    month_ = month;
}

void BitcoinExchange::Date::setDay(int day)
{
    day_ = day;
}

void BitcoinExchange::Date::setDateStr(const std::string &dateStr)
{
    dateStr_ = dateStr;
}

void BitcoinExchange::Date::setValue(float value)
{
    value_ = value;
}

// ============= Member Functions =============

bool BitcoinExchange::Date::isValid() const
{
    if (year_ < 0 || month_ < 1 || month_ > 12 || day_ < 1)
        return (false);

    int daysInMonth;
    switch (month_)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = isLeapYear() ? 29 : 28;
            break;
        default:
            return (false);
    }
    return (day_ <= daysInMonth);
}

bool BitcoinExchange::Date::isLeapYear() const
{
    return ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0));
}

// ============= Private Member Functions =============

static int ft_stoi(const std::string &s)
{
    if (s.empty())
        throw std::invalid_argument("Empty number");

    int sign = 1;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+')
    {
        if (s[0] == '-') sign = -1;
        i = 1;
    }

    int result = 0;
    for (; i < s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            throw std::invalid_argument("Non-digit character");
        result = result * 10 + (s[i] - '0');
    }
    return sign * result;
}

void BitcoinExchange::Date::parseDate(const std::string &dateStr)
{
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
    {
        throw std::invalid_argument("Date format must be YYYY-MM-DD");
    }

    try
    {
        year_ = ft_stoi(dateStr.substr(0, 4));
        month_ = ft_stoi(dateStr.substr(5, 2));
        day_ = ft_stoi(dateStr.substr(8, 2));
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Invalid date components");
    }
}
