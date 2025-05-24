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
    Zombie();
    Zombie(std::string name);

    // Destructor
    ~Zombie();

    // Setter
    void setName(std::string name);


    // Method
    void announce( void ) const;
    
};

Zombie* zombieHorde( int N, std::string name );

#endif