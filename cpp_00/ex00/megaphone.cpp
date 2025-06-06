#include <iostream>

int main(int argc, char **args)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; args[i][j]; j++)
            std::cout << (char)std::toupper(args[i][j]);
    }
    std::cout << "\n";
    return (0);
}
