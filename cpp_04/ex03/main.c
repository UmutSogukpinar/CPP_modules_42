#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== Materia Source: Learn Ice and Cure ===" << "\n";
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n=== Create Character: Umut ===" << "\n";
	Character* umut = new Character("Umut");

	std::cout << "\n=== Equip Umut with Ice and Cure ===" << "\n";
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	umut->equip(tmp1);
	umut->equip(tmp2);

	std::cout << "\n=== Create Character: Bot(Umut copy constructor) ===" << "\n";
	Character bot(*umut); // copy constructor

	std::cout << "\n=== Use materia from original Umut ===" << "\n";
	Character dummy("Dummy");
	umut->use(0, dummy); // Ice
	umut->use(1, dummy); // Cure

	std::cout << "\n=== Use materia from copied Bot ===" << "\n";
	bot.use(0, dummy); // Ice
	bot.use(1, dummy); // Cure

	std::cout << "\n=== Assignment test: Bot = Dummy ===" << "\n";
	bot = dummy; // operator=

	std::cout << "\n=== Use materia from assigned Bot ===" << "\n";
	bot.use(0, dummy); // empty
	bot.use(1, dummy); // empty

	std::cout << "\n=== Clean up ===" << "\n";
	delete umut;
	delete src;
	// dummy and bot are stack objects — no delete needed
	return 0;
}
