#include <iostream>
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Elements:" << std::endl;
	for (MutantStack<int>::mstack_iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Const iteration:" << std::endl;
	const MutantStack<int>	cmstack = mstack;

	for (MutantStack<int>::mstack_const_iterator cit = cmstack.begin(); cit != cmstack.end(); ++cit)
		std::cout << *cit << std::endl;

	return (0);
}
