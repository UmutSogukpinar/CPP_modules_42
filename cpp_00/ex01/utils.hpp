#ifndef UTILS_HPP
# define UTILS_HPP

#include "string"

enum class Status 
{
    SUCCESS,
    FAILURE,
    EXIT
};


bool    getInput(std::string* prompt);
Status  addProcess(PhoneBook* phoneBook);


#endif