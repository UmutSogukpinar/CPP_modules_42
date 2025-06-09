#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(DEFAULT_HIT_POINTS),
						energyPoints(DEFAULT_ENERGY_POINTS), attackDamage(DEFAULT_ATTACK_DAMAGE) 
{
	std::cout << "Default ClapTrap constructor called for " << name << "\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(DEFAULT_HIT_POINTS),
										energyPoints(DEFAULT_ENERGY_POINTS), attackDamage(DEFAULT_ATTACK_DAMAGE) 
{
	std::cout << "Parameterized ClapTrap constructor called for " << name << "\n";
}

// Destructor
ClapTrap::~ClapTrap() 
{
	std::cout << "Destructor called for " << name << "\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) 
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) 
{
	std::cout << "Copy constructor called for " << name << "\n";
}

// Overloaded '=' operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "Assignment operator called for " << name << "\n";
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) 
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target 
				  << ", causing " << attackDamage << " points of damage!\n";
		energyPoints--;
	}
	else if (hitPoints == 0) 
	{
		std::cout	<< "ClapTrap " << name << " cannot attack because it has no hit points left." 
					<< "\n";
	} 
	else
	{
		std::cout	<< "ClapTrap " << name << " cannot attack because it has no energy points left."
					<< "\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount) 
{
	if (hitPoints > 0)
	{
		if (hitPoints < amount)
		{
			hitPoints = 0;
		}
		else
		{
			hitPoints -= amount;
		}

		std::cout << "ClapTrap " << name << " takes " << amount 
				  << " points of damage! Remaining hit points: " << hitPoints << "\n";
	}
	else
	{
		std::cout << "ClapTrap " << name << " has already been destroyed." << "\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount) 
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout	<< "ClapTrap " << name << " repairs itself for " << amount 
					<< " points! New hit points: " << hitPoints << "\n";
	}
	else if (hitPoints == 0)
	{
		std::cout	<< "ClapTrap " << name << " cannot be repaired because it has no hit points left." 
					<< "\n";
	}
	else
	{
		std::cout	<< "ClapTrap " << name << " cannot be repaired because it has no energy points left." 
					<< "\n";
	}
}
