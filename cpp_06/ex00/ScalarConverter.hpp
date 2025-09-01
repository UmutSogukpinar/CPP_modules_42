#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include "iostream"


# define NAN		"nan"
# define NANF		"nanf"

# define IMPOSSIBLE "impossible"
# define NON_DIS	"Non displayable"

# define INT_MSG	"int   : "
# define CHAR_MSG	"char  : "
# define FLOAT_MSG	"float : "
# define DOUBLE_MSG	"double: "


class ScalarConverter
{
	private:
    	ScalarConverter();
	public:
		static void convert(const std::string& arg);
};


int ft_stoi(const std::string& input);
float ft_stof(const std::string& str);
double ft_stod(const std::string& str);

#endif