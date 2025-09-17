#include "string"
#include "iostream"
#include "RPN.hpp"

static void split(const std::string &s, char delim, std::queue<std::string> &out)
{
    std::string current;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == delim)
        {
            if (!current.empty())
            {
                out.push(current);
                current.clear();
            }
        }
        else
            current += s[i];
    }
    if (!current.empty())
        out.push(current);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << std::endl;
		return (1);
	}

	std::string arg = argv[1];
	std::queue<std::string> argQueue;

	split(arg, ' ', argQueue);

	try
	{
		RPN rpn(argQueue);

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << '\n';
	}
	
	return (0);
}