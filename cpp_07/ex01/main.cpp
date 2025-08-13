#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print_elem(T const &x) { std::cout << x << "\n"; }

template <typename T>
void increment(T &x) { ++x; }

int main()
{
	int a[] = {1, 2, 3, 4};
	std::size_t n = sizeof(a) / sizeof(a[0]);

	std::cout << "[before]\n";
	iter(a, n, print_elem<int>);
	iter(a, n, increment<int>);
	std::cout << "[after]\n";
	iter(a, n, print_elem<int>);

	std::string s[] = {"foo", "bar", "baz"};
	std::size_t m = sizeof(s) / sizeof(s[0]);
	std::cout << "[strings]\n";
	iter(s, m, print_elem<std::string>);

	const int c[] = {10, 20, 30};
	std::cout << "[const array]\n";
	iter(c, sizeof(c)/sizeof(c[0]), print_elem<int>); // works with const

	return (0);
}
