#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

// ========================================== Date ==========================================

// ============= Constructors and Destructor =============


BitcoinExchange::Date::Date() : year_(0), month_(0), day_(0), value_(0.0f){}

BitcoinExchange::Date::Date(std::string dateStr, float value) : dateStr_(dateStr), value_(value)
{
	parseDate(dateStr);
}

BitcoinExchange::Date::~Date() {}

// ============= Getters and Setters =============

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

const std::string &BitcoinExchange::Date::getDateStr() const
{
	return (dateStr_);
}

float BitcoinExchange::Date::getValue() const
{
	return (value_);
}

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
	parseDate(dateStr);
}

void BitcoinExchange::Date::setValue(float value)
{
	value_ = value;
}

// ============= Other Member Functions =============

bool BitcoinExchange::Date::isLeapYear() const
{
	return ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0));
}

bool BitcoinExchange::Date::isValidDate(int year, int month, int day) const
{
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);

	int daysInMonth[] = {31, (isLeapYear() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::Date::isValid() const
{
	return (isValidDate(year_, month_, day_));
}

void BitcoinExchange::Date::parseDate(const std::string &dateStr)
{
	std::stringstream ss(dateStr);
	char dash1;
	char dash2;

	ss >> year_ >> dash1 >> month_ >> dash2 >> day_;
	if (ss.fail() || dash1 != '-' || dash2 != '-' || !isValid())
		throw std::runtime_error("Invalid date format: " + dateStr);
}

// ========================================== BitcoinExchange ==========================================

// ============= Constructors and Destructor =============

// Default constructor
BitcoinExchange::BitcoinExchange() : file_(NULL) {}

BitcoinExchange::BitcoinExchange(std::ifstream *file) : file_(file)
{
	loadExchangeRates();
	processInputFile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		file_ = other.file_;
		exchangeRates_ = other.exchangeRates_;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates()
{
	std::ifstream db("data.csv");
	if (!db.is_open())
		throw std::runtime_error("Could not open data.csv");

	std::string line;
	std::getline(db, line); // skip header
	while (std::getline(db, line))
	{
		std::stringstream ss(line);
		std::string dateStr;
		std::string valueStr;

		if (!std::getline(ss, dateStr, ',') || !std::getline(ss, valueStr))
			continue;
		float value = std::strtof(valueStr.c_str(), NULL);
		Date date(dateStr, value);
		exchangeRates_[dateStr] = date;
	}
	db.close();
}

float BitcoinExchange::getRateForDate(const std::string &dateStr)
{
	std::map<std::string, Date>::iterator it = exchangeRates_.lower_bound(dateStr);

	if (it == exchangeRates_.end())
	{
		--it;
		return (it->second.getValue());
	}

	if (it->first == dateStr)
		return (it->second.getValue());

	if (it != exchangeRates_.begin())
	{
		--it;
		return (it->second.getValue());
	}

	throw std::runtime_error("No available exchange rate for date: " + dateStr);
}

void BitcoinExchange::processInputFile()
{
	if (!file_ || !file_->is_open())
		throw std::runtime_error("Input file not provided or not open");

	std::string line;
	std::getline(*file_, line);
	while (std::getline(*file_, line))
	{
		std::stringstream ss(line);
		std::string dateStr;
		std::string valueStr;

		if (!std::getline(ss, dateStr, '|') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		try
		{
			float inputValue = std::strtof(valueStr.c_str(), NULL);
			if (inputValue < 0)
				throw std::runtime_error("not a positive number.");
			if (inputValue > 1000)
				throw std::runtime_error("too large a number.");
			float rate = getRateForDate(dateStr);
			std::cout << dateStr << " => " << inputValue << " = " << (inputValue * rate) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << " (line: " << line << ")" << std::endl;
		}
	}
}
