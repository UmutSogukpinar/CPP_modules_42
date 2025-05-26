#include "iostream"

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of str: " << &str << "\n";
    std::cout << "Address held by stringPTR: " << stringPTR << "\n";
    std::cout << "Address held by stringREF: " << &stringREF << "\n";

    std::cout << "Value of str: " << str << "\n";
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << "\n";
    std::cout << "Value pointed to by stringREF: " << stringREF << "\n";

    return (0);
}