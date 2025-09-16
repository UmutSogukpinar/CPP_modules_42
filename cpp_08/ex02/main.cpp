#include <iostream>
#include "MutantStack.hpp"
#include <string>

int main()
{
    // ===== Basic push/pop/top/size/empty tests =====
    MutantStack<int> mstack;

    std::cout << "Pushing elements..." << std::endl;
    mstack.push(5);
    mstack.push(17);

    // Check the top element
    std::cout << "Top element: " << mstack.top() << std::endl; // Expected: 17

    // Pop one element and check size
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Expected: 1

    // Push additional elements
	std::cout << "Pushing more elements..." << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(42);

    std::cout << "Stack size now: " << mstack.size() << std::endl; // Expected: 5

    // ===== Iterate through elements using iterator =====

    std::cout << "\nIterating through stack elements (mutable):" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // ===== Iterate through elements using const_iterator =====

    const MutantStack<int> constStack(mstack);
    std::cout << "Iterating through const stack:" << std::endl;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    // ===== Test comparison operators =====

    MutantStack<int> other;
    other.push(100);
    other.push(200);

    std::cout << "\nComparison operators:" << std::endl;
    std::cout << "mstack == other? " << (mstack == other ? "true" : "false") << std::endl;
    std::cout << "mstack < other? " << (mstack < other ? "true" : "false") << std::endl;

    // ===== Use MutantStack with std::string =====

    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");
    sstack.push("mutant");
    sstack.push("stack");

    std::cout << "\nString stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
        std::cout << *sit << " ";
    std::cout << std::endl;

    // ===== Clear string stack =====

    std::cout << "\nClearing string stack:" << std::endl;
    while (!sstack.empty()) {
        std::cout << "Pop: " << sstack.top() << std::endl;
        sstack.pop();
    }

    std::cout << "Empty? " << (sstack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
