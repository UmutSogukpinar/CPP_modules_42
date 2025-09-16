#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

		// ========== Constructors & Destructor ==========

		// Default Destructor
		MutantStack();

		// Copy Constructor
		MutantStack(const MutantStack&other);

		// Destructor
        ~MutantStack();

		// Assignment operator
        MutantStack& operator=(const MutantStack& other);

        // === Iterator typedefs with explicit names ===

        typedef typename std::stack<T>::container_type::iterator         iterator;
        typedef typename std::stack<T>::container_type::const_iterator   const_iterator;


        void push(const T& value);
        void pop();
        T& top();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end()   const;

};

# include "MutantStack.tpp"


#endif

