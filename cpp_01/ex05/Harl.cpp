#include "Harl.hpp"

void Harl::complain(std::string level) 
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    const int numLevels = sizeof(levels) / sizeof(levels[0]);

    void (Harl::*funcs[])() = { 
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error 
    };

    for (int i = 0; i < numLevels; ++i) 
    {
        if (levels[i] == level)
        {
            (this->*(funcs[i]))();
            return ;
        }
    }

    std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
}

void Harl::debug( void )
{
    std::cout << "{DEBUG}" << "\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!"
              << "\n";
}

void Harl::info( void )
{
    std::cout << "{INFO}" << "\n"
              << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! "
              << "If you did, I wouldn't be asking for more!"
              << "\n";
}

void Harl::warning( void )
{
    std::cout << "{WARNING}" << "\n"
              << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working here since last month."
              << "\n";
}

void Harl::error( void )
{
    std::cout << "{ERROR}" << "\n"
              << "This is unacceptable! I want to speak to the manager now."
              << "\n";
}
