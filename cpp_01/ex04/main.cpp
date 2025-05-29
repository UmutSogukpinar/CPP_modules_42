#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

void open_input_file(std::ifstream& file, const std::string& filename);
void create_output_file(std::ofstream& file, const std::string& filename);
std::string replace_all(const std::string& text, const std::string& from, const std::string& to);

int main(int argc, char **argv) 
{
	if (argc != 4) 
	{
		std::cerr << "Usage: " << argv[0]
		          << " <file name> <string to replace> <replacement>"
                  << "\n";
		return (EXIT_FAILURE);
	}

	std::string input_filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string output_filename = input_filename + ".replace";

	std::ifstream input_file;
	std::ofstream output_file;

	open_input_file(input_file, input_filename);
	create_output_file(output_file, output_filename);

	std::string line;
	while (std::getline(input_file, line)) 
	{
		output_file << replace_all(line, s1, s2) << "\n";
	}

	input_file.close();
	output_file.close();

	return (EXIT_SUCCESS);
}

void open_input_file(std::ifstream& file, const std::string& filename)
{
	file.open(filename.c_str());
	if (!file.is_open()) 
	{
		std::cerr << "Error: Could not open input file: " << filename << "\n";
		std::exit(EXIT_FAILURE);
	}
}

void create_output_file(std::ofstream& file, const std::string& filename)
{
	file.open(filename.c_str());
	if (!file.is_open()) 
	{
		std::cerr << "Error: Could not create output file: " << filename << "\n";
		std::exit(EXIT_FAILURE);
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
