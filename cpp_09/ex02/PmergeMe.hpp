#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <stdexcept>

class PmergeMe
{
	private:
		std::vector<int> vec_;
		std::deque<int> deq_;

		void parseArgs(char **begin, char **end);
		void printContainer(const std::vector<int> &c, const std::string &msg) const;
		void mergeInsertSort(std::vector<int> &c);
		void mergeInsertSort(std::deque<int> &c);

		template <typename Container>
		void hybridSort(Container &c, size_t left, size_t right);

		template <typename Container>
		void insertionSort(Container &c, size_t left, size_t right);

		template <typename Container>
		void merge(Container &c, size_t left, size_t mid, size_t right);

	public:

		PmergeMe(char **begin, char **end);
		void run();

	private:

		
};

#endif
