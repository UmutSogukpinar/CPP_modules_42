#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	// Fields
	Fixed const x_;
	Fixed const y_;

	static float getArea_(Point const &a, Point const &b, Point const &c);

  public:
	// Default Constructor
	Point();

	// Parameterized Constructor
	Point(float const x, float const y);

	// Copy Constructor
	Point(Point const &other);

	// Destructor
	~Point();

	// Copy Assignment Operator Overload
	Point operator=(Point const &other);

	// Member Function(s)
	static bool bsp(Point const a, Point const b, Point const c,
			Point const point);
};

#endif