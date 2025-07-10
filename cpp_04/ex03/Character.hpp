#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define CAPACITY_OF_BAG 4

class Character : public ICharacter
{
	private:

		std::string name_;
		AMateria	*bag_[CAPACITY_OF_BAG];

	public:

		// Default Constructor
		Character();

		// Parameterized Constructor
		Character(std::string name);

		// Destructor
		~Character();

		// Copy Constructor
		Character(const Character& other);

		// Assignment Operator
		Character& operator=(const Character& other);
		
		// ========== Getters & Setters ==========

		std::string const & getName() const;

		// ============ Overrided Function(s) ============

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);


	
};

#endif