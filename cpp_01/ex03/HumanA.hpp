#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{

    private:

        // * Fields
        
        std::string	name_;
        Weapon		&weapon_;

    public:

        // * Constructor

        HumanA(const std::string& name, Weapon &weapon);

        // * Methods

        void attack() const;
};

#endif