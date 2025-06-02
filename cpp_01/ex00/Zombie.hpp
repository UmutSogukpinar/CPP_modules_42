#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    
    // Fields
    std::string name_;

public:

    // Constructor
    Zombie(const std::string name);

    // Destructor
    ~Zombie();

    // Method
    void announce( void ) const;
    
};

// * Mandatory Functions
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif