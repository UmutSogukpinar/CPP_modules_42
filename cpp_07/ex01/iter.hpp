#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// generic iter function
template <typename T, typename Func>
void iter(T *arr, std::size_t len, Func func)
{
    for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

// const array overload
template <typename T, typename Func>
void iter(const T *arr, std::size_t len, Func func)
{
    for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif
