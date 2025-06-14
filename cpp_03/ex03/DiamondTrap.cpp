#include "DiamondTrap.hpp"

// ====================== Constructors ======================

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name_("Default")
{
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name_(name)
{
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  name_(other.name_)
{
	std::cout << "DiamondTrap copy constructor called" << "\n";

	this->hitPoints_ = other.hitPoints_;
	this->energyPoints_ = other.energyPoints_;
	this->attackDamage_ = other.attackDamage_;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << name_ << "\n";
}

// Overloaded '=' operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);

		this->name_ = other.name_;
		std::cout << "DiamondTrap assignment operator called for " << name_ << "\n";
	}
	return (*this);
}

// ============= Member Function(s) =============

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << name_
			  << " and ClapTrap's name is " << ClapTrap::name_
			  << "\n";
}
