#include "DiamondTrap.hpp"

// ====================== Constructors ======================

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name_("Default")
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "Default DiamondTrap constructor called for " << name_ << "\n";
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(),
	  FragTrap(),
	  name_(name)
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = SCAV_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "Parameterized DiamondTrap constructor called for " << name_ << "\n";
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  name_(other.name_)
{
	this->hitPoints_ = other.hitPoints_;
	this->energyPoints_ = other.energyPoints_;
	this->attackDamage_ = other.attackDamage_;
	std::cout << "DiamondTrap copy constructor called" << "\n";
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << name_ << "\n";
}

// Overloaded '=' operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout<< "DiamondTrap Copy Assigment Called" << "\n";

    if (this == &other)
	{
        return (*this);
	}

	this->ClapTrap::name_ = other.ClapTrap::name_;
	this->hitPoints_ = other.hitPoints_;
	this->energyPoints_ = other.energyPoints_;
	this->attackDamage_ = other.attackDamage_;

	this->name_ = other.name_;

    return(*this);
}

// ============= Member Function(s) =============

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << name_
			  << " and ClapTrap's name is " << ClapTrap::name_
			  << "\n";
}
