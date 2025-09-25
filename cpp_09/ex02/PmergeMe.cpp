#include "PmergeMe.hpp"

// ===================== Constructor =====================

PmergeMe::PmergeMe(char **begin, char **end)
{
    parseArgs(begin, end);
}

// ===================== Public =====================

void PmergeMe::run()
{
    printContainer(vec_, "Before:");

    std::vector<int> vecCopy = vec_;
    std::deque<int> deqCopy = deq_;

    clock_t start = clock();
    jacobsthalSort(vecCopy);
    clock_t end = clock();
    double vecTime = (double)(end - start) * 1e6 / CLOCKS_PER_SEC;

    start = clock();
    jacobsthalSort(deqCopy);
    end = clock();
    double deqTime = (double)(end - start) * 1e6 / CLOCKS_PER_SEC;

    printContainer(vecCopy, "After:");

    std::cout << "Time to process a range of " << vec_.size()
              << " elements with std::vector : " << vecTime << " us\n";
    std::cout << "Time to process a range of " << deq_.size()
              << " elements with std::deque  : " << deqTime << " us\n";
}

// ===================== Class Utility =====================

void PmergeMe::parseArgs(char **begin, char **end)
{
    std::set<int> seen;
    for (char **it = begin; it != end; ++it)
    {
        std::string str(*it);
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(str[i])))
                throw std::invalid_argument("Error: invalid character in input");
        }
        long val = std::strtol(str.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::invalid_argument("Error: invalid number");
        if (!seen.insert((int)val).second)
            throw std::invalid_argument("Error: duplicate number");
        vec_.push_back((int)val);
        deq_.push_back((int)val);
    }
}

template <typename Container>
void PmergeMe::printContainer(const Container &c, const std::string &msg) const
{
    std::cout << msg << " ";
    for (size_t i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::jacobsthalSort(Container &c)
{
    if (c.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
    for (; i + 1 < c.size(); i += 2)
    {
        int a = c[i];
        int b = c[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    bool hasOdd = (i < c.size());
    int last = hasOdd ? c.back() : 0;

    std::sort(pairs.begin(), pairs.end(),
        [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.second < p2.second;
        });

    Container sorted;
    for (size_t j = 0; j < pairs.size(); ++j)
        sorted.push_back(pairs[j].second);

    std::vector<size_t> jacob = generateJacobsthal(pairs.size());
    std::set<size_t> inserted;

    for (size_t idx = 0; idx < jacob.size(); ++idx)
    {
        size_t pos = jacob[idx];
        if (pos == 0 || pos > pairs.size())
            continue;
        size_t realIndex = pos - 1;
        if (inserted.count(realIndex))
            continue;
        inserted.insert(realIndex);
        binaryInsert(sorted, pairs[realIndex].first);
    }

    for (size_t j = 0; j < pairs.size(); ++j)
    {
        if (!inserted.count(j))
            binaryInsert(sorted, pairs[j].first);
    }

    if (hasOdd)
        binaryInsert(sorted, last);

    c.assign(sorted.begin(), sorted.end());
}

template <typename Container>
void PmergeMe::binaryInsert(Container &sorted, int value)
{
    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) const
{
    std::vector<size_t> seq;
    size_t j1 = 0, j2 = 1;
    seq.push_back(j2);
    while (true)
    {
        size_t next = j2 + 2 * j1;
        if (next > n)
            break;
        seq.push_back(next);
        j1 = j2;
        j2 = next;
    }
    return seq;
}

// ===================== Explicit instantiations =====================

template void PmergeMe::jacobsthalSort(std::vector<int> &);
template void PmergeMe::jacobsthalSort(std::deque<int> &);
