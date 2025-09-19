#include "PmergeMe.hpp"
#include "set"
#include "climits"
#include "stdlib.h"

// ===================== Constructor =====================
PmergeMe::PmergeMe(char **begin, char **end)
{
    parseArgs(begin, end);
}

// ===================== Member Functions =====================

void PmergeMe::run()
{
    // Print before
    printContainer(vec_, "Before:");

    // Copy containers
    std::vector<int> vecCopy = vec_;
    std::deque<int> deqCopy = deq_;

    clock_t start = clock();
    mergeInsertSort(vecCopy);
    clock_t end = clock();
    double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    mergeInsertSort(deqCopy);
    end = clock();
    double deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    printContainer(vecCopy, "After:");

    std::cout << "Time to process a range of " << vec_.size()
              << " elements with std::vector : " << vecTime << " ms\n";
    std::cout << "Time to process a range of " << deq_.size()
              << " elements with std::deque  : " << deqTime << " ms\n";
}

// ===================== Private =====================
void PmergeMe::parseArgs(char **begin, char **end)
{
    std::set<int> seen;
    for (char **it = begin; it != end; ++it)
    {
        std::string str(*it);
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (!std::isdigit(str[i]))
                throw std::invalid_argument("Error: invalid character in input");
        }
        long val = strtol(str.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::invalid_argument("Error: invalid number");
        if (!seen.insert((int)val).second)
            throw std::invalid_argument("Error: duplicate number");
        vec_.push_back((int)val);
        deq_.push_back((int)val);
    }
}

void PmergeMe::printContainer(const std::vector<int> &c, const std::string &msg) const
{
    std::cout << msg << " ";
    for (size_t i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

// ===================== Sorting =====================
void PmergeMe::mergeInsertSort(std::vector<int> &c)
{
    if (c.empty())
        return;
    hybridSort(c, 0, c.size() - 1);
}

void PmergeMe::mergeInsertSort(std::deque<int> &c)
{
    if (c.empty())
        return;
    hybridSort(c, 0, c.size() - 1);
}

template <typename Container>
void PmergeMe::hybridSort(Container &c, size_t left, size_t right)
{
    const size_t threshold = 16;
    if (right - left <= threshold)
    {
        insertionSort(c, left, right);
        return;
    }
    size_t mid = (left + right) / 2;
    hybridSort(c, left, mid);
    hybridSort(c, mid + 1, right);
    merge(c, left, mid, right);
}

template <typename Container>
void PmergeMe::insertionSort(Container &c, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; ++i)
    {
        int key = c[i];
        size_t j = i;
        while (j > left && c[j - 1] > key)
        {
            c[j] = c[j - 1];
            --j;
        }
        c[j] = key;
    }
}

template <typename Container>
void PmergeMe::merge(Container &c, size_t left, size_t mid, size_t right)
{
    Container tmp;
    tmp.insert(tmp.end(), c.begin() + left, c.begin() + right + 1);

    size_t i = 0;
    size_t j = mid - left + 1;
    size_t k = left;

    while (i <= mid - left && j <= right - left)
    {
        if (tmp[i] <= tmp[j])
            c[k++] = tmp[i++];
        else
            c[k++] = tmp[j++];
    }
    while (i <= mid - left)
        c[k++] = tmp[i++];
    while (j <= right - left)
        c[k++] = tmp[j++];
}
