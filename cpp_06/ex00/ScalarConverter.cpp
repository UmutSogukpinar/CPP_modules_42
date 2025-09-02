#include "ScalarConverter.hpp"
#include "iomanip"

static void toChar(const std::string& arg);
static void toInt(const std::string& arg);
static void toFloat(const std::string& arg);
static void toDouble(const std::string& arg);

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & other)
{
	(void) other;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other)
{
	(void) other;
	return (*this);
}

void ScalarConverter::convert(const std::string& arg)
{
	std::cout << std::fixed << std::setprecision(1);
	toChar(arg);
	toInt(arg);
	toFloat(arg);
	toDouble(arg);
}

static void toChar(const std::string& arg)
{
	int convertedInt;

    try {
        convertedInt = ft_stoi(arg);

        if (convertedInt < 0 || convertedInt > 127)
            std::cout << CHAR_MSG << IMPOSSIBLE << std::endl;
        else if (convertedInt < 32 || convertedInt > 126)
            std::cout << CHAR_MSG << NON_DIS << std::endl;
        else
            std::cout << CHAR_MSG << "'" << static_cast<char>(convertedInt) << "'" << std::endl;
    }
    catch (const std::exception& e)
	{
		if (arg.size() == 1)
            std::cout << CHAR_MSG << "'" << arg[0] << "'" << std::endl;
		else
       		std::cout << CHAR_MSG << IMPOSSIBLE << std::endl;
    }
}

static void toInt(const std::string& arg)
{
	int convertedInt;

    try
    {
        convertedInt = ft_stoi(arg);
        std::cout << INT_MSG << convertedInt << std::endl;
    }
    catch (const std::exception& e)
    {
		if (arg.size() == 1)
            std::cout << INT_MSG << static_cast<int>(arg[0]) << std::endl;
		else
        	std::cout << INT_MSG << IMPOSSIBLE << std::endl;
    }
}


static void toFloat(const std::string& arg)
{	
	// Special cases
    if (arg == NAN || arg == NANF)
    {
        std::cout << FLOAT_MSG << NANF << std::endl;
        return;
    }
    if (arg == "+inf" || arg == "+inff")
    {
        std::cout << FLOAT_MSG << "+inff" << std::endl;
        return;
    }
    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << FLOAT_MSG << "-inff" << std::endl;
        return;
    }

	float convertedFloat;

	// Default pattern
    try
    {
        convertedFloat = ft_stof(arg);
        std::cout << FLOAT_MSG << convertedFloat << "f" << std::endl;
    }
    catch (const std::exception& e)
    {
        if (arg.size() == 1)
            std::cout << FLOAT_MSG << static_cast<float>(arg[0]) << "f" << std::endl;
        else
            std::cout << FLOAT_MSG << IMPOSSIBLE << std::endl;
    }
}

static void toDouble(const std::string& arg)
{
	// Special cases
    if (arg == "nan" || arg == "nanf")
    {
        std::cout << DOUBLE_MSG << "nan" << std::endl;
        return;
    }
    if (arg == "+inf" || arg == "+inff")
    {
        std::cout << DOUBLE_MSG << "+inf" << std::endl;
        return;
    }
    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << DOUBLE_MSG << "-inf" << std::endl;
        return;
    }

	double convertedDouble;

	// Default pattern
    try
    {
        convertedDouble = ft_stod(arg);
        std::cout << DOUBLE_MSG << convertedDouble << std::endl;
    }
    catch (const std::exception& e)
    {
        if (arg.size() == 1)
            std::cout << DOUBLE_MSG << static_cast<double>(arg[0]) << std::endl;
        else
            std::cout << DOUBLE_MSG << IMPOSSIBLE << std::endl;
    }
}
