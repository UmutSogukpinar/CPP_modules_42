#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("Default"),
	  hitPoints_(CLAP_TRAP_DEFAULT_HIT_POINTS),
	  energyPoints_(CLAP_TRAP_DEFAULT_ENERGY_POINTS),
	  attackDamage_(CLAP_TRAP_DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "Default ClapTrap constructor called for " << name_ << "\n";
}

ClapTrap::ClapTrap(const std::string &name)
	: name_(name),
	  hitPoints_(CLAP_TRAP_DEFAULT_HIT_POINTS),
	  energyPoints_(CLAP_TRAP_DEFAULT_ENERGY_POINTS),
	  attackDamage_(CLAP_TRAP_DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "Parameterized ClapTrap constructor called for " << name_ << "\n";
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << name_ << "\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
	: name_(other.name_),
	  hitPoints_(other.hitPoints_),
	  energyPoints_(other.energyPoints_),
	  attackDamage_(other.attackDamage_)
{
	std::cout << "ClapTrap copy constructor called for " << name_ << "\n";
}

// Overloaded '=' operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
		std::cout << "ClapTrap assignment operator called for " << name_ << "\n";
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target
				  << ", causing " << attackDamage_ << " points of damage!"
				  << " Remaing energy point(s) is/are " << (energyPoints_ - 1)
				  << "\n";
		(energyPoints_)--;
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " cannot attack because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " cannot attack because it has no energy points left."
				  << "\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
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

		std::cout << "ClapTrap " << name_ << " takes " << amount
				  << " points of damage! Remaining hit points: " << hitPoints_
				  << "\n";
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " has already been destroyed." << "\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints_ > 0 && hitPoints_ > 0)
	{
		hitPoints_ += amount;
		(energyPoints_)--;
		std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
				  << " points! New hit points: " << hitPoints_
				  << " Remaing energy point(s) is/are " << (energyPoints_ - 1)
				  << "\n";
	}
	else if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " cannot be repaired because it has no hit points left."
				  << "\n";
	}
	else
	{
		std::cout << "ClapTrap " << name_ << " cannot be repaired because it has no energy points left."
				  << "\n";
	}
}
