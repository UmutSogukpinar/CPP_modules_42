#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "iostream"

#define DEFAULT_HIT_POINTS 10
#define DEFAULT_ENERGY_POINTS 10
#define DEFAULT_ATTACK_DAMAGE 0

class ClapTrap 
{
	private:

	// Fields

	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

	public:

	// ========== Constructors ==========

	ClapTrap();
	ClapTrap(std::string name);

	// Destructor
	~ClapTrap();

	// Copy constructor
	ClapTrap(const ClapTrap& other);

	// Overloaded '=' operator
	ClapTrap& operator=(const ClapTrap& other);


	// ========== Member functions ==========

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif