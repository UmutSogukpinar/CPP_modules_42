#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define SLOT_CAPACITY 4

class Character : public ICharacter
{
	private:
		std::string	name_;
		AMateria 	*slot_[SLOT_CAPACITY];


	public:
		// * Default Constructor
		Character();

		// * Parameterized Constructor
		Character(std::string const & name);

		// * Copy Constructor
		Character(Character const & other);

		// * Destructor
		~Character();

		// * Copy Assignment
		Character & operator=(Character const & other);

		// * ============== Inherited Functions ==============

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


#endif