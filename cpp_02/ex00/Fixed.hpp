#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed 
{
    private:

        // Fields
        int                 fixedPointValue_;
        static const int    fractionalBits_ = 8;

    public:

        // Constructors
        Fixed();
        Fixed(const Fixed &other);

        // Destructor
        ~Fixed();

        // Assignment operator
        Fixed &operator=(const Fixed &other);

        // Member functions
        int getRawBits() const;
        void setRawBits(int const raw);

};


#endif