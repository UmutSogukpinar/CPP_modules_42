#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <exception>
#include <iostream>

int main()
{
	MateriaSource* src = NULL;
	Character* wizard = NULL;
	AMateria* tmp1 = NULL;
	AMateria* tmp2 = NULL;

	try
	{
		std::cout << "=== Materia Source: Learn Ice and Cure ===" << "\n";
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << "\n=== Create Character: wizard ===" << "\n";
		wizard = new Character("wizard");

		std::cout << "\n=== Equip wizard with Ice and Cure ===" << "\n";
		tmp1 = src->createMateria("ice");
		tmp2 = src->createMateria("cure");
		wizard->equip(tmp1);
		wizard->equip(tmp2);

		std::cout << "\n=== Unequip slot 1 (cure) and delete manually ===" << "\n";
		wizard->unequip(1);
		delete (tmp2);

		std::cout << "\n=== Create Character: Bot(wizard copy constructor) ===" << "\n";
		Character bot(*wizard);

		std::cout << "\n=== Use materia from original wizard ===" << "\n";
		Character dummy("Dummy");
		wizard->use(0, dummy);
		wizard->use(1, dummy);

		std::cout << "\n=== Use materia from copied Bot ===" << "\n";
		bot.use(0, dummy);
		bot.use(1, dummy);

		std::cout << "\n=== Assignment test: Bot = Dummy ===" << "\n";
		bot = dummy;

		std::cout << "\n=== Use materia from assigned Bot ===" << "\n";
		bot.use(0, dummy);
		bot.use(1, dummy);

		std::cout << "\n=== Clean up ===" << "\n";
		wizard->unequip(0);
		delete (tmp1);
		delete (wizard);
		delete (src);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
		delete (tmp1);
		delete (tmp2);
		delete (wizard);
		delete (src);
		return (1);
	}
	catch (...)
	{
		std::cerr << "Unknown exception caught." << "\n";
		delete (tmp1);
		delete (tmp2);
		delete (wizard);
		delete (src);
		return (1);
	}
	return (0);
}
