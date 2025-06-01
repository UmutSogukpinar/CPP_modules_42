#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    
    // Fields

    std::string name_;

public:

    // Constructors

    Zombie();
    Zombie(std::string name);

    // Destructor
    ~Zombie();

    // Setter
    void setName(std::string name);

    // Member Function
    void announce( void ) const;
    
};

Zombie* zombieHorde( int N, std::string name );

#endif