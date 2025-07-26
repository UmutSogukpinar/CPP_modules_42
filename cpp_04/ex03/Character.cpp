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

// * ============================== Member Function(s) ==============================

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SLOT_CAPACITY)
	{
		std::cerr << "[Warning] Invalid slot index: " << idx << "\n";
		return ;
	}

	if (!this->slot_[idx])
	{
		std::cerr << "[Info] Slot " << idx << " is empty. No Materia to use on "
		          << target.getName() << "." << "\n";
		return ;
	}

	this->slot_[idx]->use(target);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cerr << "[Warning] Trying to equip a null Materia." << "\n";
		return;
	}
	for (int i = 0; i < SLOT_CAPACITY; ++i)
	{
		if (!this->slot_[i])
		{
			this->slot_[i] = m;
			std::cout << "[Info] Materia equipped in slot " << i << "." << "\n";
			return;
		}
	}
	std::cerr << "[Warning] All slots are full. Cannot equip more Materia." << "\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= SLOT_CAPACITY)
	{
		std::cerr << "[Warning] Invalid slot index: " << idx << "\n";
		return;
	}
	if (!this->slot_[idx])
	{
		std::cerr << "[Info] Slot " << idx << " is already empty." << "\n";
		return;
	}
	std::cout << "[Info] Materia unequipped from slot " << idx << "." << "\n";
	this->slot_[idx] = NULL;
}
