#include "Harl.hpp"

void Harl::complain(std::string level) 
{
    Status status = UNKNOWN;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) 
    {
        if (level == levels[i]) {
            status = static_cast<Status>(i);
            break;
        }
    }

    switch (status) 
    {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
    }
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
              << "You didn’t put enough bacon in my burger! "
              << "If you did, I wouldn’t be asking for more!"
              << "\n";
}

void Harl::warning( void )
{
    std::cout << "{WARNING}" << "\n"
              << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working here since last month."
              << "\n";
}

void Harl::error( void )
{
    std::cout << "{ERROR}" << "\n"
              << "This is unacceptable! I want to speak to the manager now."
              << "\n";
}
