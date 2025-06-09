#include "ScavTrap.hpp"

// ================== Constructors ==================

ScavTrap::ScavTrap(): ClapTrap()
{
    hitPoints = SCAV_TRAP_DEFAULT_HIT_POINTS;
    energyPoints = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
    attackDamage = SCAV_TRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< "Default ScavTrap constructor called for "
				<< name << "\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
    hitPoints = SCAV_TRAP_DEFAULT_HIT_POINTS;
    energyPoints = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
    attackDamage = SCAV_TRAP_DEFAULT_ATTACK_DAMAGE;

    std::cout << "Parameterized ScavTrap constructor called for " << name << "\n";
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << name << "\n";
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << name << "\n";
}

// Overloaded '=' operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ScavTrap assignment operator called for " << name << "\n";
	}
	return (*this);
}

// =========================== Inherited Functions ===========================

void	ScavTrap::attack(const std::string& target) 
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!"
				  << " Remaing energy point(s) is/are " << energyPoints - 1
				  << "\n";

		energyPoints--;
	}
	else if (hitPoints == 0) 
	{
		std::cout	<< "ScavTrap " << name 
					<< " cannot attack because it has no hit points left."
					<< "\n";
	}
	else
	{
		std::cout	<< "ScavTrap " << name 
					<< " cannot attack because it has no energy points left."
					<< "\n";
	}
}

void	ScavTrap::takeDamage(unsigned int amount) 
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

		std::cout << "ScavTrap " << name << " takes " << amount 
				  << " points of damage! Remaining hit points: " << hitPoints << "\n";
	}
	else
	{
		std::cout << "ScavTrap " << name << " has already been destroyed." << "\n";
	}
}

void	ScavTrap::beRepaired(unsigned int amount) 
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout	<< "ScavTrap " << name << " repairs itself for " << amount 
					<< " points! New hit points: " << hitPoints
					<< " Remaing energy point(s) is/are " << energyPoints - 1
					<< "\n";
	}
	else if (hitPoints == 0)
	{
		std::cout	<< "ScavTrap " << name << " cannot be repaired because it has no hit points left." 
					<< "\n";
	}
	else
	{
		std::cout	<< "ScavTrap " << name << " cannot be repaired because it has no energy points left." 
					<< "\n";
	}
}

// ================== Member Function(s) ==================

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap " << name
				<< " is now in Gatekeeper mode." 
				<< "\n";
}
