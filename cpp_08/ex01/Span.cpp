#include <stdexcept>
#include "Span.hpp"
#include <algorithm>

// ================ Constructors / Destructors =================

// Default constructor
Span::Span(): n_(0), numbers_() {}

// Parameterized constructor
Span::Span(std::size_t n): n_(n), numbers_() {}

// Copy constructor
Span::Span(Span const &other): n_(other.n_), numbers_(other.numbers_) {}

// Destructor
Span::~Span() {}

// Assignment operator
Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        n_ = other.n_;
        numbers_ = other.numbers_;
    }

    return (*this);
}

// ================ Member Functions =================

void Span::addNumber(int number)
{
    if (numbers_.size() >= n_)
        throw std::overflow_error("Cannot add more numbers!");

    numbers_.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + numbers_.size() > n_)
        throw std::overflow_error("Cannot add more numbers!");

    numbers_.insert(numbers_.end(), begin, end);
}

std::size_t Span::shortestSpan() const
{
    if (numbers_.size() < 2)
        throw std::logic_error("Not enough numbers to find a span!");

    std::vector<int> sortedVector = numbers_;
    std::sort(sortedVector.begin(), sortedVector.end());

    unsigned int minSpan = sortedVector[1] - sortedVector[0];
    unsigned int currentSpan;

    for (size_t i = 1; i < sortedVector.size(); ++i)
    {
        currentSpan = sortedVector[i] - sortedVector[i - 1];

        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }

    return (minSpan);
}

std::size_t Span::longestSpan() const
{
    if (numbers_.size() < 2)
        throw std::logic_error("Not enough numbers to find a span!");

    int minElement = *std::min_element(numbers_.begin(), numbers_.end());
    int maxElement = *std::max_element(numbers_.begin(), numbers_.end());

    return (maxElement - minElement);
}
