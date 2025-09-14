template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typedef typename T::iterator t_iter;

	t_iter it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("easyfind: value not found");

	return (it);
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
	typedef typename T::const_iterator t_const_iter;

	t_const_iter it = std::find(container.begin(), container.end(), value);
    
	if (it == container.end())
		throw std::out_of_range("easyfind: value not found");

	return (it);
}
