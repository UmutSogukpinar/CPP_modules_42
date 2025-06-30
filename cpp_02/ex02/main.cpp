#include "Fixed.hpp"
#include "cstdlib"

int	main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	{
		std::cout << "--- Default construction ---\n";
		Fixed a;
		std::cout << "a: " << a << "\n";

		std::cout << "\n--- Arithmetic operations ---\n";
		Fixed b(5.05f);
		Fixed c(2);
		Fixed d = b * c;
		std::cout << "b: " << b << ", c: " << c << ", b * c: " << d << "\n";

		Fixed e = b + c;
		std::cout << "b + c: " << e << "\n";

		Fixed f = b - c;
		std::cout << "b - c: " << f << "\n";

		try
		{
			Fixed g = b / Fixed(0);
			std::cout << "b / 0: " << g << "\n";
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Caught exception: " << ex.what() << "\n";
		}

		std::cout << "\n--- Increment operators ---\n";
		std::cout << "a: " << a << "\n";
		std::cout << "++a: " << ++a << "\n";
		std::cout << "a: " << a << "\n";
		std::cout << "a++: " << a++ << "\n";
		std::cout << "a: " << a << "\n";

		std::cout << "\n--- Comparison ---\n";
		Fixed const result = Fixed::max(a, d);
		std::cout << "max(a, d): " << result << "\n";
	}

	return (EXIT_SUCCESS);
}
