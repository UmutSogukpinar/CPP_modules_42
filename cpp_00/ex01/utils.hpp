#ifndef UTILS_HPP
# define UTILS_HPP

#include "string"

enum    Status 
{
    SUCCESS,
    FAILURE,
    EXIT
};


bool    getInput(std::string* prompt);
Status  addProcess(PhoneBook* phoneBook);
Status searchProcess(PhoneBook* phoneBook);


#endif