#include "iostream"
#include <unistd.h>
#include "identify.hpp"

int main(void)
{

    for (int i = 0; i < 5; i++)
    {
        Base *ptr = generate();

        std::cout << "[*] identify(Base*): ";
        identify(ptr);

        std::cout << "[&] identify(Base&): ";
        identify(*ptr);

        delete ptr;
        std::cout << "--------------------" << std::endl;
		sleep(1);
    }
    return (0);
}
