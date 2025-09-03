#include <iostream>
#include <string>
#include "Array.hpp"

static void print_header(const char *title)
{
    std::cout << "\n=== " << title << " ===\n";
}

int main()
{
    print_header("default-constructed (empty)");
    Array<int> defaultARray;
    std::cout << "size=" << defaultARray.size() << "\n";

    print_header("size ctor + value-init");
    Array<int> intArray(5);

    for (std::size_t i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";

    std::cout << "\n";

    for (std::size_t i = 0; i < intArray.size(); ++i)
        intArray[i] = (int)i + 1;

    print_header("copy ctor (deep copy)");
    Array<int> copyArray = intArray;
    intArray[0] = 42;
    std::cout << "ai[0]=" << intArray[0] << ", bi[0]=" << copyArray[0] << " (bi unaffected)\n";

    print_header("strings");
    Array<std::string> stringArray(3);
    stringArray[0] = "foo"; stringArray[1] = "bar"; stringArray[2] = "baz";
    for (std::size_t i = 0; i < stringArray.size(); ++i)
        std::cout << stringArray[i] << " ";
    std::cout << "\n";

    print_header("const access");
    Array<std::string> cs = stringArray;
    const Array<std::string> &r = cs;
    std::cout << r[1] << "\n";

    print_header("out_of_range check");
    try {
        std::cout << intArray[999] << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "caught: " << e.what() << "\n";
    }

    return (0);
}
