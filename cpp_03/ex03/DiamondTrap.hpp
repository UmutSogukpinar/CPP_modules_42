#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name_;

public:
	// ========== Constructors ==========
	DiamondTrap();
	DiamondTrap(const std::string &name);

	// Copy Constructor
	DiamondTrap(const DiamondTrap &other);

	// Destructor
	~DiamondTrap();

	// Overloaded '=' operator
	DiamondTrap &operator=(const DiamondTrap &other);

	// ============= Member Function(s) =============
	
	void whoAmI();


};

#endif