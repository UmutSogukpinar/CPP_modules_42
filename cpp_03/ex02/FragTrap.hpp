#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define FRAG_TRAP_DEFAULT_HIT_POINTS 100
#define FRAG_TRAP_DEFAULT_ENERGY_POINTS 100
#define FRAG_TRAP_DEFAULT_ATTACK_DAMAGE	30

class FragTrap : protected ClapTrap
{
public:
	// ========== Constructors ==========

	FragTrap();
	FragTrap(const std::string &name);

	// Copy Constructor
	FragTrap(const FragTrap &other);

	// ========== Destructor ==========
	~FragTrap();

	// ====== Overloaded '=' operator ======
	FragTrap &operator=(const FragTrap &other);

	// ====== Inherited Functions ======

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// ====== Member Function(s) ======

	void highFivesGuys();
};

#endif