#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	// Fields
	int fixedPointValue_;
	static const int fractionalBits_ = 8;

  public:
	// Constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);

	// Destructor
	~Fixed();

	// Assignment operator
	Fixed &operator=(const Fixed &other);

	// Member functions
	float toFloat() const;
	int toInt() const;

	// Getters and Setters
	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif