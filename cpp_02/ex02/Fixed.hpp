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

	// Member function(s)
	float toFloat() const;
	int toInt() const;

	// Getters and Setters

	int getRawBits() const;
	void setRawBits(int const raw);

	// Overloaded comparison operators

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Overloaded arithmetic operators

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	//  Increment-Decrement

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	// Max and Min functions
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif