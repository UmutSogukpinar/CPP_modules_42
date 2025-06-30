#include "Point.hpp"

static void testBsp(const char* label, Point const &a, Point const &b, Point const &c, Point const &p, bool expected);

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "---- BSP FUNCTION TESTS (strict: no edge or vertex) ----\n";

	testBsp("Inside", a, b, c, Point(5.0f, 5.0f), true);

	testBsp("Edge (base)", a, b, c, Point(5.0f, 0.0f), false);

	testBsp("Vertex (point A)", a, b, c, a, false);

	testBsp("Outside", a, b, c, Point(10.0f, 10.0f), false);

	std::cout << "\n---- DEGENERATE TRIANGLE TESTS ----\n";

	Point same(1.0f, 1.0f);
	testBsp("All points same", same, same, same, same, false);

	Point colinear1(0.0f, 0.0f);
	Point colinear2(5.0f, 5.0f);
	Point colinear3(10.0f, 10.0f);
	Point onLine(2.5f, 2.5f);
	testBsp("Colinear points", colinear1, colinear2, colinear3, onLine, false);

	return 0;
}

static void testBsp(const char* label, Point const &a, Point const &b, Point const &c, Point const &p, bool expected)
{
	bool result = Point::bsp(a, b, c, p);

	std::cout << label << ": ";
	std::cout << (result ? "INSIDE ✅" : "OUTSIDE ❌");

	if (result != expected)
		std::cout << "  ← Unexpected ❗️";
	else
		std::cout << "  ← Expected ✅";

	std::cout << "\n";
}
