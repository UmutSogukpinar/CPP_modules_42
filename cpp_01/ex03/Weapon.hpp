#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon 
{
    private:

        // * Fields

        std::string type_;

    public:


        // * Constructor
        Weapon(const std::string type);

        // * Getters and Setters

        const std::string& getType() const;
        void setType(const std::string& newType);
};


#endif