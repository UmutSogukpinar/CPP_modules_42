#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
    private:
        unsigned int n_;
        std::vector<int> numbers_;

	public:

        // ================ Constructors / Destructors =================
        Span();
        Span(unsigned int n);
        Span(Span const &other);
        ~Span();

        // Assignment operator
        Span &operator=(Span const &other);

        // ================ Member Functions =================

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif