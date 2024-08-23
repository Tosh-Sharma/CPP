#include "PmergeMe.hpp"

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

std::deque<int> PmergeMe::generateJacobsthal(int size) {
	std::deque<int>	jacobsthal;

	jacobsthal.push_back(1);
	int i = 3;

	while (i <= size) {
		jacobsthal.push_back(i);
		i = 2 * jacobsthal[jacobsthal.size() - 1] + 1;
	}
	return jacobsthal;
}

int PmergeMe::binarySearch(const std::deque<int>& mainSequence, int value, int end) {
	int	left = 0, right = end;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (mainSequence[mid] < value) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

void PmergeMe::insertIntoMainSequence(std::deque<int>& mainSequence, int value, int end) {
	int pos = binarySearch(mainSequence, value, end);
	mainSequence.insert(mainSequence.begin() + pos, value);
}

void PmergeMe::mergeInsertionSort(std::deque<int>& inputDeque) {
	std::deque<std::pair<int, int> > pairs;

	std::deque<int>	mainSequence;
	std::deque<int> secondSequence;
	std::deque<int> jacobsthal;
	size_t			iterator = 0;

	if (inputDeque.size() <= 1) {
		return;
	}
	// Create pairs of elements. {Step 1}
	for ( ;iterator + 1 < inputDeque.size(); iterator += 2) {
		if (inputDeque[iterator] > inputDeque[iterator + 1]) {
			pairs.push_back(std::make_pair(inputDeque[iterator + 1], inputDeque[iterator]));
		} else {
			pairs.push_back(std::make_pair(inputDeque[iterator], inputDeque[iterator + 1]));
		}
	}

	iterator = 0;
	// Create a main sequence and a second sequence. {Step 2}
	for (; iterator < pairs.size(); ++iterator) {
		mainSequence.push_back(pairs[iterator].first);
		secondSequence.push_back(pairs[iterator].second);
	}
	if (inputDeque.size() % 2 == 1) {
		mainSequence.push_back(inputDeque.back());
	}
	// Sort the main sequence out recursively. {Step 4}
	this->mergeInsertionSort(mainSequence);

	jacobsthal = generateJacobsthal(secondSequence.size());
	iterator = 0;
	// Insert the second sequence into the main sequence. {Step 5}
	for ( ; iterator < secondSequence.size(); ++iterator) {
		insertIntoMainSequence(mainSequence, secondSequence[iterator], mainSequence.size());
	}
	inputDeque = mainSequence;
}
