#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
    private:
        std::size_t n_;
        std::vector<int> numbers_;

	public:

        // ================ Constructors / Destructors =================
        Span();
        Span(std::size_t n);
        Span(Span const &other);
        ~Span();

        // Assignment operator
        Span &operator=(Span const &other);

        // ================ Member Functions =================

        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        std::size_t shortestSpan() const;
        std::size_t longestSpan() const;
};

#endif