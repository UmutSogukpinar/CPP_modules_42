#ifndef WRONGANIMAL_CPP
# define WRONGANIMAL_CPP

#include "iostream"

class WrongAnimal
{
protected:
	std::string type_;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	void makeSound() const;

};

#endif
