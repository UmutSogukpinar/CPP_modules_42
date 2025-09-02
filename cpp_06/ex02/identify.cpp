#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly create A, B, or C
Base* generate(void)
{
    std::srand((std::time(NULL)));
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
        std::cout << "NULL" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
        return ;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
        return ;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
        return ;
    }
    std::cout << "Unknown" << std::endl;
}

// Identify via reference
void identify(Base& p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...){}

    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...){}

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...){}

    std::cout << "Unknown" << std::endl;
}
