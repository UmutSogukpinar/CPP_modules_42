#include "PmergeMe.hpp"

// ===================== Constructor =====================

PmergeMe::PmergeMe(char **begin, char **end)
{
    parseArgs(begin, end);
}

// ===================== Public ====================

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

// ===================== Argument Parsing =====================

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

// ===================== Utility =====================

template <typename Container>
void PmergeMe::printContainer(const Container &c, const std::string &msg) const
{
    std::cout << msg << " ";
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Comparator for pairs (sort by .second ascending)
struct PairComp
{
    bool operator()(const std::pair<int,int> &p1, const std::pair<int,int> &p2) const
    {
        return (p1.second < p2.second);
    }
};

// ===================== Jacobsthal Sort =====================

template <typename Container>
void PmergeMe::jacobsthalSort(Container &container)
{
    if (container.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;

    for (; i + 1 < container.size(); i += 2)
    {
        int left = container[i];
        int right = container[i + 1];
        if (left > right)
            std::swap(left, right);
        pairs.push_back(std::make_pair(left, right));
    }

    bool hasOdd = (i < container.size());
    int last = hasOdd ? container.back() : 0;

    std::sort(pairs.begin(), pairs.end(), PairComp());

    Container sorted;
    for (size_t j = 0; j < pairs.size(); ++j)
        sorted.push_back(pairs[j].second);

    std::vector<size_t> jacob = generateJacobsthal(pairs.size());
    std::set<size_t> inserted;

    for (size_t k = 0; k < jacob.size(); ++k)
    {
        size_t pos = jacob[k];
        if (pos == 0 || pos > pairs.size())
            continue;
        size_t index = pos - 1;
        if (inserted.count(index))
            continue;
        inserted.insert(index);
        binaryInsert(sorted, pairs[index].first);
    }

    for (size_t j = 0; j < pairs.size(); ++j)
    {
        if (!inserted.count(j))
            binaryInsert(sorted, pairs[j].first);
    }

    if (hasOdd)
        binaryInsert(sorted, last);

    container.assign(sorted.begin(), sorted.end());
}

// ===================== Binary Insert =====================

template <typename Container>
void PmergeMe::binaryInsert(Container &sorted, int value)
{
    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

// ===================== Jacobsthal Sequence =====================

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) const
{
    std::vector<size_t> seq;
    size_t j1 = 0;
    size_t j2 = 1;

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

// ===================== Explicit Instantiations =====================

template void PmergeMe::jacobsthalSort(std::vector<int> &);
template void PmergeMe::jacobsthalSort(std::deque<int> &);
template void PmergeMe::binaryInsert(std::vector<int> &, int);
template void PmergeMe::binaryInsert(std::deque<int> &, int);
template void PmergeMe::printContainer(const std::vector<int>&, const std::string&) const;
template void PmergeMe::printContainer(const std::deque<int>&, const std::string&) const;
