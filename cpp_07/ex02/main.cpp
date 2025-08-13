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
    Array<int> a0;
    std::cout << "size=" << a0.size() << "\n";

    print_header("size ctor + value-init");
    Array<int> ai(5);

    for (std::size_t i = 0; i < ai.size(); ++i)
        std::cout << ai[i] << " ";

    std::cout << "\n";

    for (std::size_t i = 0; i < ai.size(); ++i)
        ai[i] = (int)i + 1;

    print_header("copy ctor (deep copy)");
    Array<int> bi = ai;
    ai[0] = 42; // modify original
    std::cout << "ai[0]=" << ai[0] << ", bi[0]=" << bi[0] << " (bi unaffected)\n";

    print_header("strings");
    Array<std::string> as(3);
    as[0] = "foo"; as[1] = "bar"; as[2] = "baz";
    for (std::size_t i = 0; i < as.size(); ++i)
        std::cout << as[i] << " ";
    std::cout << "\n";

    print_header("const access");
    Array<std::string> cs = as;
    const Array<std::string> &r = cs;
    std::cout << r[1] << "\n";

    print_header("out_of_range check");
    try {
        std::cout << ai[999] << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "caught: " << e.what() << "\n";
    }

    return (0);
}
