#include "Fixed.hpp"
#include "cstdlib"

int main(void)
{
	try
	{
		Fixed a;
		Fixed b(a);
		Fixed c;
		c = b;

		std::cout << a.getRawBits() << "\n";
		std::cout << b.getRawBits() << "\n";
		std::cout << c.getRawBits() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "An exception occurred: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unknown exception occured" << "\n";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
