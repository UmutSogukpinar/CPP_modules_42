#include "FragTrap.hpp"

// ================== Constructors ==================

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = FRAG_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout << "Default FragTrap constructor called for "
			  << name_ << "\n";
}

FragTrap::FragTrap(const std::string &name_) : ClapTrap(name_)
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = FRAG_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout << "Parameterized FragTrap constructor called for " << name_ << "\n";
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << name_ << "\n";
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << name_ << "\n";
}

// Overloaded '=' operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		std::cout << "FragTrap assignment operator called for " << name_ << "\n";
	}
	return (*this);
}

// =========================== Inherited Functions ===========================

void FragTrap::attack(const std::string &target)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		std::cout << "FragTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!"
				  << " Remaing energy point(s) is/are " << (energyPoints_ - 1)
				  << "\n";

		energyPoints_--;
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "FragTrap " << name_
				  << " cannot attack because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "FragTrap " << name_
				  << " cannot attack because it has no energy points left."
				  << "\n";
	}
}

void FragTrap::takeDamage(unsigned int amount)
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

		std::cout << "FragTrap " << name_ << " takes " << amount
				  << " points of damage! Remaining hit points: "
				  << hitPoints_ << "\n";
	}
	else
	{
		std::cout << "FragTrap " << name_
				  << " has already been destroyed." << "\n";
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		hitPoints_ += amount;
		(energyPoints_)--;
		std::cout << "FragTrap " << name_ << " repairs itself for " << amount
				  << " points! New hit points: " << hitPoints_
				  << " Remaing energy point(s) is/are " << (energyPoints_ - 1)
				  << "\n";
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "FragTrap " << name_
				  << " cannot be repaired because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "FragTrap " << name_
				  << " cannot be repaired because it has no energy points left."
				  << "\n";
	}
}

// ================== Member Function(s) ==================

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_
			  << " salutes and says: 'High five, soldier. "
			  << "Another mission well executed.'"
			  << "\n";
}
