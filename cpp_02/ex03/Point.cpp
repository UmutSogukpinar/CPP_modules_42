#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{
	std::cout << "Default Constructor called for Point instance" << "\n";
}

Point::Point(float const x, float const y): x_(x), y_(y)
{
	std::cout << "Parameterized Constructor called for Point instance" << "\n";
}

Point::Point(Point const &other): x_(other.x_), y_(other.y_)
{
	std::cout << "Copy Constructor called for Point instance" << "\n";
}

Point::~Point()
{
	std::cout << "Destructor called for Point instance" << "\n";
}

Point Point::operator=(Point const &other)
{
	(void) other;
	std::cout << "Assignment operator called for Point instance" << "\n";
	return (*this);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
    float totalArea = getArea_(a, b, c);
    float area1 = getArea_(point, b, c);
    float area2 = getArea_(a, point, c);
    float area3 = getArea_(a, b, point);

    float sum = area1 + area2 + area3;
    float marginOfError = 0.00001f;

	float difference = (totalArea - sum) > 0 ? (totalArea - sum) : -(totalArea - sum); 
    bool isInside = difference < marginOfError;

    if (area1 == 0.0f || area2 == 0.0f || area3 == 0.0f)
        return (false);

    return (isInside);
}

float Point::getArea_(Point const &a, Point const &b, Point const &c)
{
    float ax = a.x_.toFloat();
    float ay = a.y_.toFloat();
    float bx = b.x_.toFloat();
    float by = b.y_.toFloat();
    float cx = c.x_.toFloat();
    float cy = c.y_.toFloat();

    float determinant = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by);

    return ((determinant > 0 ? determinant : -determinant) * 0.5f);
}
