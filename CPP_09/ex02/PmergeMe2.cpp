#include "PmergeMe2.hpp"

PmergeMe::PmergeMe () {}

PmergeMe::~PmergeMe () {}

PmergeMe::PmergeMe (const PmergeMe &other)
{
	(void)other;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return (*this);
}

// Function to generate the Jacobsthal sequence up to a given size
std::deque<int> PmergeMe::generateJacobsthal(int n) {
	std::deque<int> jacobsthal;
	jacobsthal.push_back(1);
	int i = 3;
	while (i <= n) {
		jacobsthal.push_back(i);
		i = 2 * jacobsthal[jacobsthal.size() - 1] + 1;
	}
	return jacobsthal;
}

// Binary search to find the correct insertion point for an element
int PmergeMe::binarySearch(const std::deque<int>& main_chain, int b, int end) {
	int left = 0, right = end;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (main_chain[mid] < b) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

// Function to insert element in the main chain
void PmergeMe::insertIntoMainChain(std::deque<int>& main_chain, int b, int end) {
	int pos = binarySearch(main_chain, b, end);
	main_chain.insert(main_chain.begin() + pos, b);
}

// Recursive Merge Insertion Sort function
void PmergeMe::mergeInsertionSort(std::deque<int>& vec) {
	if (vec.size() <= 1) {
		return;
	}

	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1]) {
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		} else {
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
	}

	std::deque<int> main_chain;
	std::deque<int> bs;
	for (size_t i = 0; i < pairs.size(); ++i) {
		main_chain.push_back(pairs[i].first);
		bs.push_back(pairs[i].second);
	}

	if (vec.size() % 2 == 1) {
		main_chain.push_back(vec.back());
	}

	this->mergeInsertionSort(main_chain);

	std::deque<int> jacobsthal = generateJacobsthal(bs.size());

	for (size_t i = 0; i < bs.size(); ++i) {
		insertIntoMainChain(main_chain, bs[i], main_chain.size());
	}
	vec = main_chain;
}
