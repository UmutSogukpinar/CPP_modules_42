#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return (*this);
        }
        ~MutantStack() {}

        // === Iterator typedefs with explicit names ===
        typedef typename std::stack<T>::container_type::iterator         mstack_iterator;
        typedef typename std::stack<T>::container_type::const_iterator   mstack_const_iterator;

        mstack_iterator begin() { return this->c.begin(); }
        mstack_iterator end()   { return this->c.end(); }
        mstack_const_iterator begin() const { return this->c.begin(); }
        mstack_const_iterator end()   const { return this->c.end(); }
};

#endif
