#include "Fixed.hpp"
#include <cmath>

// ============================ Constructors ============================

// Default constructor
Fixed::Fixed()
	: fixedPointValue_(0)
{
	std::cout << "Default constructor called for Fixed instance"
				<< "\n";
}

// Constructor with integer parameter
Fixed::Fixed(const int value)
	: fixedPointValue_(value * (1 << fractionalBits_))
{
	std::cout << "Integer constructor called for Fixed instance"
				<< "\n";
}

// Constructor with float parameter
Fixed::Fixed(const float value)
	: fixedPointValue_(roundf(value * (1 << fractionalBits_)))
{
	std::cout << "Float constructor called for Fixed instance"
				<< "\n";
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
	: fixedPointValue_(other.fixedPointValue_)
{
	std::cout << "Copy constructor called for Fixed instance"
				<< "\n";
}

// ====================== Destructor ======================
Fixed::~Fixed()
{
	std::cout << "Destructor called for fixed instance"
				<< "\n";
}

// ====================== Assignment operator ======================
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called for Fixed instance"
				<< "\n";
	if (this != &other)
	{
		fixedPointValue_ = other.fixedPointValue_;
	}
	return (*this);
}

// ====================== Getters and Setters ======================

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called"
				<< "\n";

	return (fixedPointValue_);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called"
				<< "\n";
	fixedPointValue_ = raw;
}

// ====================== Member Function(s) ======================

// To convert fixed-point value to float
float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue_) / (1 << fractionalBits_));
}

// To convert fixed-point value to integer
int Fixed::toInt(void) const
{
	return (roundf(static_cast<float>(fixedPointValue_)
			/ (1 << fractionalBits_)));
}

// Overloaded output operator for Fixed class
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// ========================  Overloaded comparison operators ========================
bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixedPointValue_ > other.fixedPointValue_);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixedPointValue_ < other.fixedPointValue_);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixedPointValue_ >= other.fixedPointValue_);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixedPointValue_ <= other.fixedPointValue_);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixedPointValue_ == other.fixedPointValue_);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixedPointValue_ != other.fixedPointValue_);
}

// ==================  Overloaded arithmetic operators =================

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.fixedPointValue_ = this->fixedPointValue_ + other.fixedPointValue_;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.fixedPointValue_ = this->fixedPointValue_ - other.fixedPointValue_;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	long long mul = static_cast<long long>(this->fixedPointValue_)
		* other.fixedPointValue_;
	result.fixedPointValue_ = static_cast<int>(mul / (1 << fractionalBits_));

	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	if (other.fixedPointValue_ == 0)
		throw std::runtime_error("Division by zero");

	long long numerator = static_cast<long long>(this->fixedPointValue_)
		* (1 << fractionalBits_);
	long long division = numerator / other.fixedPointValue_;
	result.fixedPointValue_ = static_cast<int>(division);

	return (result);
}

// ===================== Increment-Decrement =====================

Fixed Fixed::operator++()
{
	fixedPointValue_ += 1;
	return (*this);
}

Fixed Fixed::operator--()
{
	fixedPointValue_ -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixedPointValue_ += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixedPointValue_ -= 1;
	return (temp);
}

// ======================= Max-Min Functions =======================

// Static member function to find the maximum of two Fixed objects
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

// Static member function to find the maximum of two Fixed objects
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

// Static member function to find the minimum of two Fixed objects
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

// Static member function to find the minimum of two Fixed objects
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}
