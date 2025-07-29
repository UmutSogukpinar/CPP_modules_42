#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void test_basic();
static void test_animal_array();
static void test_deep_copy();


int main(void)
{
	try
	{
		test_basic();

		std::cout << "===================== Extra Subject Request =====================" << "\n";

		test_animal_array();
		test_deep_copy();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << "\n";
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void test_basic()
{
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* animal = new Animal();

	delete cat;
	delete dog;
	delete animal;
}

static void test_animal_array()
{
	const int kAnimalArraySize = 10;
	int i = 0;

	Animal* animals[kAnimalArraySize];

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

static void test_deep_copy()
{
	std::cout << "==================== Deep Copy Test ====================\n";

	Dog dog1;

	Brain* brain1 = dog1.getBrainAddress();
	brain1->setIdea(0, "Catch the ball");
	brain1->setIdea(1, "Eat kibble");

	Dog dog2 = dog1;

	std::cout << "Dog1 Idea[0]: " << dog1.getBrainAddress()->getIdea(0) << "\n";
	std::cout << "Dog2 Idea[0]: " << dog2.getBrainAddress()->getIdea(0) << "\n";


	Brain* brain2 = dog2.getBrainAddress();
	brain2->setIdea(0, "Chew the shoes");

	std::cout << "\nAfter modifying dog2:\n";
	std::cout << "Dog1 Idea[0]: " << dog1.getBrainAddress()->getIdea(0) << "\n";
	std::cout << "Dog2 Idea[0]: " << dog2.getBrainAddress()->getIdea(0) << "\n";

	if (dog1.getBrainAddress() != dog2.getBrainAddress())
		std::cout << "\nDeep copy confirmed: Brains are separate instances\n";
	else
		std::cout << "\nShallow copy detected: Both dogs share the same Brain\n";
}

