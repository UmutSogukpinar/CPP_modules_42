#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define ICE	"ice"

class Ice
{
	public:
		Ice();
		~Ice();

		AMateria* clone() const;
};



#endif