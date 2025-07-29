#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "iostream"

# define NUM_IDEAS 100

class Brain
{
private:
	std::string ideas[NUM_IDEAS];

public:
	// Default Constructor
	Brain();

	// Copy Constructor and 
	Brain(const Brain& other);

	// Assignment '=' Operator
	Brain& operator=(const Brain& other);

	// Destructor
	~Brain();

	// Getter and Setter
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

	// Display Ideas
	void displayIdeas() const;


};


#endif