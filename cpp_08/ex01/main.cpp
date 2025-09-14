#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Output: 2
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Output: 14

    try
    {
        sp.addNumber(42); // Capacity exceeded
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    return (0);
}