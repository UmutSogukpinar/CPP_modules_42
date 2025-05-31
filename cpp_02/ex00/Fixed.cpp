#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointValue_(0) 
{
    std::cout << "Default constructor called" << "\n";
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
