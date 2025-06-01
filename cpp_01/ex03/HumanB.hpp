#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{

    private:

        // * Fields
        
        std::string	name_;
        Weapon*		weapon_;

    public:

        // * Constructor

        HumanB(std::string name);

        // * Getters and Setters
        void setWeapon(Weapon& weapon);

        // * Methods

        void attack() const;
};

#endif