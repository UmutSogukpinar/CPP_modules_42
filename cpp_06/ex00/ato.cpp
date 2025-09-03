#include <climits>
#include <cfloat>
#include "iostream"

static std::string trim(const std::string& s){
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
int ft_stoi(const std::string& input){
    std::string str = trim(input);
    if (str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;

    if (str[i] == '-'){
        sign = -1;
        i++;
    } else if (str[i] == '+')
        i++;

    if (i >= str.size() || !std::isdigit(static_cast<unsigned char>(str[i])))
        throw std::invalid_argument("No digits found");

    long long acc = 0;
    bool dotSeen = false;
    bool hasDigit = false;
	int digit;
	unsigned char c;

    for (; i < str.size(); i++){
        c = static_cast<unsigned char>(str[i]);

        if (std::isdigit(c)){
            digit = c - '0';
            if (acc > (INT_MAX - digit) / 10)
                throw std::out_of_range("Out of range");

            acc = acc * 10 + digit;
            hasDigit = true;
        } else if (c == '.' && !dotSeen){
            dotSeen = true;
            while (i + 1 < str.size() &&
                   std::isdigit(static_cast<unsigned char>(str[i + 1])))
            {
                i++;
            }
            continue ;
        } else if ((c == 'f' || c == 'F') && i == str.size() - 1)
            break;
        else
            throw std::invalid_argument("Invalid character in int");
    }

    if (!hasDigit)
        throw std::invalid_argument("No digits found");

    acc *= sign;

    if (acc < INT_MIN || acc > INT_MAX)
        throw std::out_of_range("Out of range");

    return (static_cast<int>(acc));
}

// string -> float
float ft_stof(const std::string& str){
    std::string trimmed_str = trim(str);
    if (trimmed_str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;

    if (trimmed_str[i] == '-'){
        sign = -1;
		i++;
	}
    else if (trimmed_str[i] == '+')
        i++;

    if (i >= trimmed_str.size() || (!std::isdigit(trimmed_str[i]) && trimmed_str[i] != '.'))
        throw std::invalid_argument("No digits found");

    double result = 0.0;
    bool dotSeen = false;
    double fracDiv = 1.0;
	char c;
	int digit;
	double addition;

    for (; i < trimmed_str.size(); i++){
        c = trimmed_str[i];

        if (std::isdigit(static_cast<unsigned char>(c))){
            digit = c - '0';

            if (!dotSeen){
                if (result > (FLT_MAX - digit) / 10.0)
			        throw std::out_of_range("Out of float range");

                result = result * 10.0 + digit;
            } else {
                fracDiv *= 10.0;
                addition = digit / fracDiv;

                if (result > FLT_MAX - addition)
                    throw std::out_of_range("Out of float range");

                result += addition;
            }
        } else if (c == '.' && !dotSeen)
            dotSeen = true;
        else if ((c == 'f' || c == 'F') && i == trimmed_str.size() - 1)
            break;
        else
            throw std::invalid_argument("Invalid character in float string");
    }
    result *= sign;
    if (result > FLT_MAX || result < -FLT_MAX)
        throw std::out_of_range("Out of float range");
    return (static_cast<float>(result));
}

// string -> double
double ft_stod(const std::string& str){
    std::string trimmed_str = trim(str);
    if (trimmed_str.empty())
        throw std::invalid_argument("Empty string!");

    size_t i = 0;
    int sign = 1;

    if (trimmed_str[i] == '-')
	{
        sign = -1;
		i++;

	}
    else if (trimmed_str[i] == '+')
        i++;

    if (i >= trimmed_str.size() || (!std::isdigit(trimmed_str[i]) && trimmed_str[i] != '.'))
        throw std::invalid_argument("No digits found");

    long double result = 0.0;
    bool dotSeen = false;
    long double fracDiv = 1.0;
	long double addition;
	char c;

    for (; i < trimmed_str.size(); i++){
        c = trimmed_str[i];
        if (std::isdigit(static_cast<unsigned char>(c))){
            int digit = c - '0';

            if (!dotSeen){
                if (result > (DBL_MAX - digit) / 10.0)
                    throw std::out_of_range("Out of double range");

                result = result * 10.0 + digit;
            } else{
                fracDiv *= 10.0;
                addition = digit / fracDiv;

                if (result > DBL_MAX - addition)
                    throw std::out_of_range("Out of dobule range");

                result += addition;
            }
        }
        else if (c == '.' && !dotSeen)
            dotSeen = true;
        else if ((c == 'f' || c == 'F') && i == trimmed_str.size() - 1)
            break;
        else
            throw std::invalid_argument("Invalid character");
    }

    result *= sign;

    if (result > DBL_MAX || result < -DBL_MAX)
        throw std::out_of_range("Out of dobule range");

    return (static_cast<double>(result));
}
