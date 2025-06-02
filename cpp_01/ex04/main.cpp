#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

static void open_input_file(std::ifstream& file, const std::string& filename);
static void create_output_file(std::ofstream& file, const std::string& filename);
std::string replace_all(const std::string& text, const std::string& from, const std::string& to);

int main(int argc, char **argv) 
{
	try 
	{
		if (argc != 4) 
		{
			throw std::invalid_argument("Usage: <file name> <string to replace> <replacement>");
		}

		std::string input_filename = argv[1];
		std::string from = argv[2];
		std::string to = argv[3];
		std::string output_filename = input_filename + ".replace";

		std::ifstream input_file;
		std::ofstream output_file;

		open_input_file(input_file, input_filename);
		create_output_file(output_file, output_filename);

		std::string line;
		while (std::getline(input_file, line)) 
		{
			output_file << replace_all(line, from, to) << "\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

static void open_input_file(std::ifstream& file, const std::string& filename)
{
	file.open(filename.c_str());
	if (!file.is_open()) 
	{
		throw std::runtime_error("Could not open input file: " + filename);
	}
}

static void create_output_file(std::ofstream& file, const std::string& filename)
{
	file.open(filename.c_str());
	if (!file.is_open()) 
	{
		throw std::runtime_error("Could not create output file: " + filename);
	}
}

std::string replace_all(const std::string& text, const std::string& from, const std::string& to)
{
	if (from.empty())
    {
		return (text);
    }

	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found;

	while ((found = text.find(from, pos)) != std::string::npos)
	{
		result += text.substr(pos, found - pos);
		result += to;
		pos = found + from.length();
	}
	result += text.substr(pos);

	return (result);
}
