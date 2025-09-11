#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print_elem(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	++x;
}

int main()
{
	int intArray[] = {1, 2, 3, 4};
	std::size_t sizeIntArray = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "[before]" << std::endl;
	::iter(intArray, sizeIntArray, print_elem<int>);
	::iter(intArray, sizeIntArray, increment<int>);
	std::cout << "[after]" << std::endl;
	::iter(intArray, sizeIntArray, print_elem<int>);

	std::string stringArray[] = {"one", "two", "three"};
	std::size_t sizeStringArray = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << "[strings]" << std::endl;
	::iter(stringArray, sizeStringArray, print_elem<std::string>);

	const int constArray[] = {10, 20, 30};
	std::cout << "[const array]" << std::endl;
	::iter(constArray, sizeof(constArray)/sizeof(constArray[0]), print_elem<int>); // works with const

	return (0);
}
