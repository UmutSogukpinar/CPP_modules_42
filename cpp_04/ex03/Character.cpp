#include "Character.hpp"

// * ============================== Constructors ==============================

Character::Character(): name_(DEFAULT)
{
	for (int i = 0; i < SLOT_CAPACITY; ++i)
		slot_[i] = NULL;
};

Character::Character(std::string const & name) : name_(name)
{
	for (int i = 0; i < SLOT_CAPACITY; ++i)
		slot_[i] = NULL;
};

Character::Character(Character const & other) : name_(other.name_)
{
	for (int i = 0; i < SLOT_CAPACITY; ++i)
	{
		if (other.slot_[i])
			this->slot_[i] = other.slot_[i]->clone();
		else
			this->slot_[i] = NULL;
	}
}

// * Destructor
Character::~Character()
{
	for (int i = 0; i < SLOT_CAPACITY; ++i)
	{
		delete (this->slot_[i]);
		this->slot_[i] = NULL;
	}
}

// * Assignment Operator
Character & Character::operator=(Character const & other)
{
	if (this != &other)
	{
		this->name_ = other.name_;
		for (int i = 0; i < SLOT_CAPACITY; ++i)
		{
			if (other.slot_[i])
			{
				delete (this->slot_[i]);
				this->slot_[i] = other.slot_[i]->clone();
			}
			else
				this->slot_[i] = NULL;
		}
	}
	return (*this);
}

// * Getter
std::string const & Character::getName() const
{
	return (this->name_);
}

