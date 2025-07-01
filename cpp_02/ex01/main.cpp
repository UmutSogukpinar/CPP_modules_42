#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

int main( void ) 
{
	try
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

		// ===================== Negative case ====================
		std::cout << "\n";

		Fixed const e(-42);
		Fixed const f(-42.42f);
		Fixed const g(-34.62f);

		std::cout << "e is " << e << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;

		std::cout << "f is " << f << std::endl;
		std::cout << "f is " << f.toInt() << " as integer" << std::endl;

		std::cout << "g is " << g << std::endl;
		std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred!" << "\n";
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
