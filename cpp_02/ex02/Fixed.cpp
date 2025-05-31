#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : fixedPointValue_(0) 
{
    std::cout << "Default constructor called" << "\n";
}

// Constructor with integer parameter
Fixed::Fixed(const int value) : fixedPointValue_(value << fractionalBits_) 
{
    std::cout << "Int constructor called" << "\n";
}

// Constructor with float parameter
Fixed::Fixed(const float value) 
{
    fixedPointValue_ = roundf(value * (1 << fractionalBits_));
    
    std::cout << "Float constructor called" << "\n";
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : fixedPointValue_(other.fixedPointValue_) 
{
    std::cout << "Copy constructor called" << "\n";
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << "\n";
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << "\n";

    if (this != &other) 
    {
        fixedPointValue_ = other.fixedPointValue_;
    }

    return (*this);
}

// ====== Getters and Setters =====
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << "\n";

    return (fixedPointValue_);
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << "\n";

    fixedPointValue_ = raw;
}

// To convert fixed-point value to float
float Fixed::toFloat(void) const 
{
    return (float)fixedPointValue_ / (1 << fractionalBits_);
}

// To convert fixed-point value to integer
int Fixed::toInt(void) const 
{
    return (fixedPointValue_ >> fractionalBits_);
}

// Overloaded output operator for Fixed class
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

// ========  Overloaded comparison operators ========
bool Fixed::operator>(const Fixed& other) const 
{
    return (this->fixedPointValue_ > other.fixedPointValue_);
}

bool Fixed::operator<(const Fixed& other) const 
{
    return (this->fixedPointValue_ < other.fixedPointValue_);
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return (this->fixedPointValue_ >= other.fixedPointValue_);
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return (this->fixedPointValue_ <= other.fixedPointValue_);
}

bool Fixed::operator==(const Fixed& other) const 
{
    return (this->fixedPointValue_ == other.fixedPointValue_);
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return (this->fixedPointValue_ != other.fixedPointValue_);
}

// ==========  Overloaded arithmetic operators =========

Fixed Fixed::operator+(const Fixed& other) const 
{
    Fixed result;

    result.fixedPointValue_ = this->fixedPointValue_ + other.fixedPointValue_;
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    Fixed result;

    result.fixedPointValue_ = this->fixedPointValue_ - other.fixedPointValue_;
    return (result);
}

// Static member function to find the maximum of two Fixed objects
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b) ? a : b);
}

// Static member function to find the maximum of two Fixed objects
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return ((a > b) ? a : b);
}

// Static member function to find the minimum of two Fixed objects
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b) ? a : b);
}

// Static member function to find the minimum of two Fixed objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return ((a < b) ? a : b);
}