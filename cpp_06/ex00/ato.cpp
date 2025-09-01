#include <string>
#include <stdexcept>
#include <climits>
#include <cfloat>
#include <cctype>

static std::string trim(const std::string& s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        start++;

    if (start == s.size())
        return ("");

    size_t end = s.size() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(s[end])))
        end--;

    return (s.substr(start, end - start + 1));
}

// string -> int
int ft_stoi(const std::string& input)
{
    std::string str = trim(input);

    if (str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;

    // sign check
    if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
    else if (str[i] == '+') i++;

    if (i >= str.size() || !std::isdigit(static_cast<unsigned char>(str[i])))
        throw std::invalid_argument("No digits found");

    long result = 0;
    for (; i < str.size(); i++)
    {
        char c = str[i];
        if (!std::isdigit(static_cast<unsigned char>(c)))
            throw std::invalid_argument("Trailing characters not allowed");

        int digit = c - '0';
        if (result > (LONG_MAX - digit) / 10)
            throw std::out_of_range("Out of range");

        result = result * 10 + digit;
    }

    result *= sign;

    if (result < INT_MIN || result > INT_MAX)
        throw std::out_of_range("Out of range");

    return (static_cast<int>(result));
}

// string -> float
float ft_stof(const std::string& str)
{
    std::string trimmed_str = trim(str);
    if (str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;
    if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
    else if (str[i] == '+') i++;

    if (i >= str.size() || (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '.'))
        throw std::invalid_argument("No digits found");

    double result = 0.0;
    bool dotSeen = false;
    double fracDiv = 1.0;

    for (; i < str.size(); i++)
    {
        char c = str[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
		{
            int digit = c - '0';
            if (!dotSeen) 
                result = result * 10.0 + digit;
            else
			{
                fracDiv *= 10.0;
                result += digit / fracDiv;
            }
        }
        else if (c == '.' && !dotSeen)
            dotSeen = true;
        else if ((c == 'f' || c == 'F') && i == str.size() - 1) 
            break; // suffix 'f' is allowed for float
        else
            throw std::invalid_argument("Invalid character in float");
    }

    result *= sign;

    if (result > FLT_MAX || result < -FLT_MAX)
        throw std::out_of_range("Out of range");

    return (static_cast<float>(result));
}

// string -> double
double ft_stod(const std::string& str)
{
    std::string trimmed_str = trim(str);
    if (str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;

    if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
    else if (str[i] == '+')
		i++;

    if (i >= str.size() || (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '.'))
        throw std::invalid_argument("No digits found");

    long double result = 0.0;
    bool dotSeen = false;
    long double fracDiv = 1.0;

    for (; i < str.size(); i++)
    {
        char c = str[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
		{
            int digit = c - '0';
            if (!dotSeen) 
                result = result * 10.0 + digit;
            else
			{
                fracDiv *= 10.0;
                result += digit / fracDiv;
            }
        }
        else if (c == '.' && !dotSeen) 
            dotSeen = true;
        else 
            throw std::invalid_argument("Invalid character");
    }

    result *= sign;

    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::out_of_range("Out of range");

    return (static_cast<double>(result));
}
