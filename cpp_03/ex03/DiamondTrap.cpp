#include "DiamondTrap.hpp"

// ======================  Constructors ======================

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name_("Default")
{
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

