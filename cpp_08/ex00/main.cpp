#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;

	try
	{
		v.push_back(1);
		v.push_back(3);
		v.push_back(5);

		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try {
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found in vector: " << *it << "\n";
		*it = 100;
	}
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

	try {
		std::list<int> const &cl = l; // const view
		std::list<int>::const_iterator it = easyfind(cl, 20);
		std::cout << "Found in list: " << *it << "\n";
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

	try {
		easyfind(v, 42);
	}
    catch (const std::exception &e)
    { 
        std::cerr << "Error: " << e.what() << "\n";
    }

	std::cout << "Vector now: ";
	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
	std::cout << "\n";

	return (0);
}
