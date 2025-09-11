#ifndef ITER_HPP
# define ITER_HPP

// custom iter function
template <typename T, typename FuncReturnType>
void iter(T *arr, std::size_t len, FuncReturnType const &func)
{
	for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

// custom iter function (includes const type)
template <typename T, typename FuncReturnType>
void iter(T const *arr, std::size_t len, FuncReturnType const &func)
{
	for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif
