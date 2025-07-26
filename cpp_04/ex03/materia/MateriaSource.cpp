#include "MateriaSource.hpp"


// Default Constructor
MateriaSource::MateriaSource()
{
	for (int i = 0; i < MS_SLOT_CAPACITY; ++i)
		this->slot_[i] = NULL;
}

// Copy Constructor
MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < MS_SLOT_CAPACITY; ++i)
	{
        if (other.slot_[i])
        {
            this->slot_[i] = other.slot_[i]->clone();
        }
        else
        {
            this->slot_[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->slot_[i];
			this->slot_[i] = NULL;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (other.slot_[i])
				this->slot_[i] = other.slot_[i]->clone();
			else
				this->slot_[i] = NULL;
		}
	}

	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MS_SLOT_CAPACITY; ++i)
	{
		delete (this->slot_[i]);
		this->slot_[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cerr << "[Warning] Trying to learn a null Materia." << "\n";
		return;
	}
	for (int i = 0; i < MS_SLOT_CAPACITY; ++i)
	{
		if (!this->slot_[i])
		{
			this->slot_[i] = m;
			std::cout << "[Info] Materia of type " << m->getType()
			          << " learned in slot " << i << "." << "\n";
			return;
		}
	}
	std::cerr << "[Warning] MateriaSource is full. Cannot learn more Materias." << "\n";
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < MS_SLOT_CAPACITY; ++i)
	{
		if (this->slot_[i] && this->slot_[i]->getType() == type)
		{
			std::cout << "[Info] Cloning Materia of type " << type << " from slot " << i << "." << "\n";
			return this->slot_[i]->clone();
		}
	}
	std::cerr << "[Warning] Unknown Materia type: " << type << "\n";
	return (NULL);
}

