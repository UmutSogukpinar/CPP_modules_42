#include "FragTrap.hpp"

// ================== Constructors ==================

FragTrap::FragTrap()
	: ClapTrap()
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = FRAG_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "Default FragTrap constructor called for "
				<< name_ << "\n";
}

FragTrap::FragTrap(const std::string &name_)
	: ClapTrap(name_)
{
	hitPoints_ = FRAG_TRAP_DEFAULT_HIT_POINTS;
	energyPoints_ = FRAG_TRAP_DEFAULT_ENERGY_POINTS;
	attackDamage_ = FRAG_TRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "Parameterized FragTrap constructor called for " << name_ << "\n";
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << name_ << "\n";
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << name_ << "\n";
}

// Overloaded '=' operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout<< "FragTrap Copy Assigment Called" << "\n";

    if (this == &other)
        return (*this);

    this->hitPoints_ = other.hitPoints_;
    this->attackDamage_ = other.attackDamage_;
    this->energyPoints_ = other.energyPoints_;
    this->name_ = other.name_;

    return(*this);
}

// ================== Member Function(s) ==================

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_
				<< " salutes and says: 'High five, soldier. "
				<< "Another mission well executed.'"
				<< "\n";
}
