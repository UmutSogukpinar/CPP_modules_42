#include "Character.hpp"

// ================== Constructors ==================

Character::Character() : name_("Default")
{
	for (int i = 0; i < CAPACITY_OF_BAG; ++i)
		bag_[i] = NULL;
}

Character::Character(std::string name) : name_(name)
{
	for (int i = 0; i < CAPACITY_OF_BAG; ++i)
		bag_[i] = NULL;
}

Character::Character(const Character &other): name_(other.name_)
{
	for (int i = 0; i < 4; i++)
    {
    	this->bag_[i] = other.bag_[i]->clone();
    }
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < CAPACITY_OF_BAG; ++i)
	{
		if (bag_[i])
			delete (bag_[i]);
	}
}

// Assignment operator 
Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return(*this);
    this->name_ = other.name_;
    for (int i = 0; i < 4; i++)
    {
        delete this->bag_[i];
        this->bag_[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (other.bag_[i] != NULL)
            this->bag_[i] = other.bag_[i]->clone();
        else
            this->bag_[i] = NULL;
    }

    return (*this);
}

// ============= Getters & Setters =============

std::string const &Character::getName(void) const
{
	return (name_);
}

// ============ Overrided Function(s) ============

void	Character::use(int idx, ICharacter& target)
{
	if (bag_[idx] == NULL)
	{
		std::cout << "There is no available materia in " << idx << "\n";
	}
	else
	{
		bag_[idx]->use(target);
	}
}
