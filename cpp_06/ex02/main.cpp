#include "iostream"
#include <cstdlib>
#include <ctime>
#include "identify.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 5; i++)
    {
        Base *ptr = generate();

        std::cout << "[*] identify(Base*): ";
        identify(ptr);

        std::cout << "[&] identify(Base&): ";
        identify(*ptr);

        delete ptr;
        std::cout << "--------------------\n";
    }
    return (0);
}
