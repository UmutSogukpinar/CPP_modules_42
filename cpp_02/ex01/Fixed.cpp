#include "Fixed.hpp"
#include <cmath>

// ============================ Constructors ============================

// Default constructor
Fixed::Fixed() : fixedPointValue_(0) 
{
    std::cout << "Default constructor called" << "\n";
}

// Constructor with integer parameter
Fixed::Fixed(const int value) : fixedPointValue_(value * (1 << fractionalBits_)) 
{
    std::cout << "Integer constructor called" << "\n";
}

// Constructor with float parameter
Fixed::Fixed(const float value)
	: fixedPointValue_(roundf(value * (1 << fractionalBits_)))
{   
    std::cout << "Float constructor called" << "\n";
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : fixedPointValue_(other.fixedPointValue_) 
{
    std::cout << "Copy constructor called" << "\n";
}

// ====================== Destructor ======================
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << "\n";
}

// ====================== Assignment operator ======================
Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << "\n";

    if (this != &other) 
    {
        fixedPointValue_ = other.fixedPointValue_;
    }

    return (*this);
}

// ====================== Getters and Setters ======================

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

// ====================== Member Function(s) ======================

// To convert fixed-point value to float
float Fixed::toFloat(void) const 
{
    return ((float)fixedPointValue_ / (1 << fractionalBits_));
}

// To convert fixed-point value to integer
int Fixed::toInt(void) const 
{
    return (roundf(fixedPointValue_ / (1 << fractionalBits_)));
}

// Overloaded output operator for Fixed class
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
