#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

# define MS_SLOT_CAPACITY 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* slot_[MS_SLOT_CAPACITY];

    public:

        // Default Constructor
        MateriaSource();

        // Copy Constructor
        MateriaSource(const MateriaSource& other);

        // Copy Asssigment Operator
        MateriaSource& operator=(const MateriaSource& other);

        // Destructor
        ~MateriaSource();

        // ============== Inherited Functions ==============

        void        learnMateria(AMateria* m);
        AMateria*   createMateria(const std::string& type);
};



#endif