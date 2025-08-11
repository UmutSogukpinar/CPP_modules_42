#include <iostream>
#include <cstdlib>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly create A, B, or C
Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
        return (new A());
    if (r == 1)
        return (new B());
    return (new C());
}

// Identify via pointer (dynamic_cast to pointer)
void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Null\n";
        return ;
    }
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A\n";
        return ;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B\n";
        return ;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C\n";
        return ;
    }
    std::cout << "Unknown\n";
}

// Identify via reference (no pointer allowed, no <typeinfo>)
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch (...) {}

    std::cout << "Unknown\n";
}
