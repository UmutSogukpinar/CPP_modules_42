#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name_;

public:

	// Constructor
	DiamondTrap();

	// Destructor
	~DiamondTrap();


};


#endif