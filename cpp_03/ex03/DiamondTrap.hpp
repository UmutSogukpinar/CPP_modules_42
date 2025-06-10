#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : protected ScavTrap, protected FragTrap
{
private:
	/* data */

public:
	DiamondTrap();
	~DiamondTrap();
};


#endif