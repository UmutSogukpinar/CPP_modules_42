#include "exception"
#include "cstdlib"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* animal = NULL;
    Animal* dog    = NULL;
    Animal* cat    = NULL;

    WrongAnimal* wrongAnimal = NULL;
    WrongAnimal* wrongCat    = NULL;
    try 
    {
        animal = new Animal();
        dog    = new Dog();
        cat    = new Cat();

        wrongAnimal = new WrongAnimal();
        wrongCat    = new WrongCat();


        std::cout << "\n" << dog->getType() << "\n";
        std::cout << cat->getType() << "\n\n";

        dog->makeSound();
        cat->makeSound();
        animal->makeSound();
        std::cout << "\n";
        wrongAnimal->makeSound();
        wrongCat->makeSound();
        std::cout << "\n";
    }
    catch (const std::exception& e) 
	{
        std::cerr << "Exception caught: " << e.what() << "\n";

		delete animal;
    	delete dog;
    	delete cat;
        delete wrongAnimal;
        delete wrongCat;
		return (EXIT_FAILURE);
    }

    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;
    delete animal;

    return (EXIT_SUCCESS);
}
