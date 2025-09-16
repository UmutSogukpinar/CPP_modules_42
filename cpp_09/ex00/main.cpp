#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    std::string dataFileName = "data.csv";
    std::string inputFileName = argv[1];

    // ? Does throw an exception if the file cannot be opened?
    std::ifstream file(dataFileName.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    BitcoinExchange exchange();

    return 0;
}
