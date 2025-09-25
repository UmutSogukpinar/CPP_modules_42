#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <set>
# include <climits>
# include <cstdlib>
# include <ctime>
# include <stdexcept>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> vec_;
        std::deque<int> deq_;

        void parseArgs(char **begin, char **end);

        template <typename Container>
        void printContainer(const Container &c, const std::string &msg) const;

        template <typename Container>
        void jacobsthalSort(Container &c);

        template <typename Container>
        void binaryInsert(Container &sorted, int value);

        std::vector<size_t> generateJacobsthal(size_t n) const;

    public:
        PmergeMe(char **begin, char **end);
        void run();
};

#endif
