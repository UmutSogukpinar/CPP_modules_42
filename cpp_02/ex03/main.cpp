#include "Point.hpp"
#include "cstdlib"
#include "exception"

static void testBsp(const char* label, Point  &a, Point  &b, Point  &c, Point  &p, bool expected);

int main(void)
{
	try
	{
		Point a(0.0f, 0.0f);
		Point b(10.0f, 0.0f);
		Point c(5.0f, 10.0f);

		std::cout << "---- BSP FUNCTION TESTS (strict: no edge or vertex) ----\n";

		Point inside(5.0f, 5.0f);
		Point edge(5.0f, 0.0f);
		Point outside(10.0f, 10.0f);

		testBsp("Inside", a, b, c, inside, true);
		testBsp("Edge (base)", a, b, c, edge, false);
		testBsp("Vertex (point A)", a, b, c, a, false);
		testBsp("Outside", a, b, c, outside, false);

		std::cout << "\n---- DEGENERATE TRIANGLE TESTS ----\n";

		Point same(1.0f, 1.0f);
		testBsp("All points same", same, same, same, same, false);

		Point colinear1(0.0f, 0.0f);
		Point colinear2(5.0f, 5.0f);
		Point colinear3(10.0f, 10.0f);
		Point onLine(2.5f, 2.5f);
		testBsp("Colinear points", colinear1, colinear2, colinear3, onLine, false);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred!\n";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


static void testBsp(const char* label, Point &a, Point &b, Point &c, Point &p, bool expected)
{
	bool result = p.bsp(a, b, c, p);

	std::cout << label << ": ";
	std::cout << (result ? "OK" : "KO");

	if (result != expected)
		std::cout << "  <- Unexpected";
	else
		std::cout << "  <- Expected";

	std::cout << "\n";
}
