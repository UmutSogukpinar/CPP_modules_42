#include "string"
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./converter <literal>" << std::endl;
        return (1);
    }

    std::string arg = argv[1];

    ScalarConverter::convert(arg);

    return (0);
}
