#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

const int kAnimalArraySize = 10;

void test_basic()
{
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	// const Animal* animal = new Animal();

	delete cat;
	delete dog;
	// delete animal;
}

void test_animal_array()
{
	Animal* animals[kAnimalArraySize];
	int i = 0;

	while (i < kAnimalArraySize / 2)
	{
		animals[i] = new Dog();
		i++;
	}
	while (i < kAnimalArraySize)
	{
		animals[i] = new Cat();
		i++;
	}
	while (--i >= 0)
		delete animals[i];
}

int main(void)
{
	try
	{
		test_basic();

		std::cout << "===================== Extra Subject Request =====================" << "\n";

		test_animal_array();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
