#include <iostream>
#include <string>
#include "Array.hpp"

static void print_header(const char *title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    // defaultArray: default constructor
    print_header("default constructed");
    Array<int> defaultArray;
    std::cout << "size=" << defaultArray.size() << std::endl;

    // intArray
    print_header("int array");
    Array<int> intArray(5);

    for (std::size_t i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";

    std::cout << std::endl;

    for (std::size_t i = 0; i < intArray.size(); ++i)
        intArray[i] = (int)i + 1;

    // copyArray: copy ctor
    print_header("copy ctor");
    Array<int> copyArray = intArray;
    intArray[0] = 42;
    std::cout << "intArray[0]= " << intArray[0] << ", copyArray[0]= " << copyArray[0] << " (copyArray unaffected)" << std::endl;

    // stringArray
    print_header("strings");
    Array<std::string> stringArray(3);
    stringArray[0] = "element 1";
	stringArray[1] = "element 2";
	stringArray[2] = "element 3";

    for (std::size_t i = 0; i < stringArray.size(); ++i)
        std::cout << stringArray[i] << " ";
    std::cout << std::endl;

    // cs and r: const access test
    print_header("const access");
    Array<std::string> cs = stringArray;
    const Array<std::string> &r = cs;
    std::cout << r[1] << std::endl;

    // intArray: out_of_range check
    print_header("out_of_range check");
    try {
        std::cout << intArray[999] << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
	
    return (0);
}

