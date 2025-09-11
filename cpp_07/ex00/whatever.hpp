#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// swap two data with each other
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// returns minimum data base on its type
template <typename T>
T const &min(T const &a, T const &b)
{
    return ((b <= a) ? b : a);
}

// returns maximum data base on its type
template <typename T>
T const &max(T const &a, T const &b)
{
    return ((b >= a) ? b : a);
}

#endif
