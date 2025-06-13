#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define SCAV_TRAP_DEFAULT_HIT_POINTS 100
#define SCAV_TRAP_DEFAULT_ENERGY_POINTS 50
#define SCAV_TRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
public:
	// ========== Constructors ==========

	ScavTrap();
	ScavTrap(const std::string &name);

	// Copy Constructor
	ScavTrap(const ScavTrap &other);

	// ========== Destructor ==========
	~ScavTrap();

	// ====== Overloaded '=' operator ======
	ScavTrap &operator=(const ScavTrap &other);

	// ====== Inherited Function(s) ======

	void attack(const std::string &target);

	// ====== Member Function(s) ======

	void guardGate();
};

#endif