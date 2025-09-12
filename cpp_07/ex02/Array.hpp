#ifndef ARRAY_HPP
#define ARRAY_HPP

# include "cstddef"

template <typename T>
class Array
{
    private:
        T          *data_;
        std::size_t size_;
    
    public:
        Array();
        explicit Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        T       &operator[](std::size_t idx);
        const T &operator[](std::size_t idx) const;

        std::size_t size() const;

};

# include "Array.tpp"

#endif
