#include "ScavTrap.hpp"

// ================== Constructors ==================

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints_ = SCAV_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = SCAV_TRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout << "Default ScavTrap constructor called for "
			  << name_ << "\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints_ = SCAV_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = SCAV_TRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout << "Parameterized ScavTrap constructor called for "
			  << name_ << "\n";
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << name_ << "\n";
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << name_ << "\n";
}

// Overloaded '=' operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		std::cout << "ScavTrap assignment operator called for "
				  << name_ << "\n";
	}
	return (*this);
}

// =========================== Inherited Functions ===========================

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!"
				  << " Remaing energy point(s) is/are " << energyPoints_ - 1
				  << "\n";

		energyPoints_--;
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "ScavTrap " << name_
				  << " cannot attack because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "ScavTrap " << name_
				  << " cannot attack because it has no energy points left."
				  << "\n";
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ > 0)
	{
		if (hitPoints_ < amount)
		{
			hitPoints_ = 0;
		}
		else
		{
			hitPoints_ -= amount;
		}

		std::cout << "ScavTrap " << name_ << " takes " << amount
				  << " points of damage! Remaining hit points: "
				  << hitPoints_ << "\n";
	}
	else
	{
		std::cout << "ScavTrap " << name_
				  << " has already been destroyed." << "\n";
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		hitPoints_ += amount;
		energyPoints_--;
		std::cout << "ScavTrap " << name_ << " repairs itself for " << amount
				  << " points! New hit points: " << hitPoints_
				  << " Remaing energy point(s) is/are " << energyPoints_ - 1
				  << "\n";
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "ScavTrap " << name_
				  << " cannot be repaired because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "ScavTrap " << name_
				  << " cannot be repaired because it has no energy points left."
				  << "\n";
	}
}

// ================== Member Function(s) ==================

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_
			  << " is now in Gatekeeper mode."
			  << "\n";
}
