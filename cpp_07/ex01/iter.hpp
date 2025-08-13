#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename Func>
void iter(T *arr, std::size_t len, Func const &func)
{
	for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

template <typename T, typename Func>
void iter(T const *arr, std::size_t len, Func const &func)
{
	for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif
