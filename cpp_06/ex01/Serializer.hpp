#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "iostream"
# include "stdint.h"
# include "data.hpp"

class Serializer
{
    private:

        // Default Constructor
        Serializer();

        // Copy Constructor
        Serializer(Serializer const & other);

        // Copy Assignment
        Serializer & operator=(Serializer const & other);

        // Destructor
        ~Serializer();

    public:

        static uintptr_t serialize(Data *ptr);

        static Data *deserialize(uintptr_t raw);
};


#endif