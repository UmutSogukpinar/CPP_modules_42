#include "iostream"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

const int kAnimalArraySize = 10;

void test_individual_animals()
{
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* animal = new Animal();

	delete cat;
	delete dog;
	delete animal;
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
	test_individual_animals();

	std::cout << "===================== Extra Subject Request =====================" << "\n";

	test_animal_array();

	return (EXIT_SUCCESS);
}
