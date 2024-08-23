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

int PmergeMe::binarySearch(const std::deque<int>& mainSequence, int value, int end) {
	int	left;
	int	right;

	left = 0;
	right = end;
	while(left < right) {
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
	int	position;

	position = binarySearch(mainSequence, value, end);
	mainSequence.insert(mainSequence.begin() + position, value);
}

void PmergeMe::mergeInsertionSort(std::deque<int>& inputDeque) {
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>						mainSequence;
	std::deque<int> 					secondSequence;
	size_t								iterator = 0;

	if (inputDeque.size() <= 1) {
		return;
	}
	// Create pairs of elements. {Step 1}
	for ( ;iterator + 1 < inputDeque.size(); iterator += 2)
	{
		if (inputDeque[iterator] > inputDeque[iterator + 1]) {
			pairs.push_back(std::make_pair(inputDeque[iterator + 1],
					inputDeque[iterator]));
		} else {
			pairs.push_back(std::make_pair(inputDeque[iterator],
					inputDeque[iterator + 1]));
		}
	}

	// Create a main sequence and a second sequence. {Step 2}
	iterator = 0;
	for (; iterator < pairs.size(); ++iterator) {
		mainSequence.push_back(pairs[iterator].first);
		secondSequence.push_back(pairs[iterator].second);
	}
	if (inputDeque.size() % 2 == 1) {
		mainSequence.push_back(inputDeque.back());
	}

	// Sort the main sequence recursively. {Step 4}
	this->mergeInsertionSort(mainSequence);

	iterator = 0;
	// Insert the second sequence into the main sequence using binary search. {Step 5}
	for ( ; iterator < secondSequence.size(); ++iterator) {
		insertIntoMainSequence(mainSequence, secondSequence[iterator],
			mainSequence.size());
	}
	inputDeque = mainSequence;
}

// Ford Johnson Algorithm for std::list

int PmergeMe::binarySearch(const std::list<int>& mainSequence, int value, int end) {
    int left = 0;
    int right = end;
    std::list<int>::const_iterator it = mainSequence.begin();

    while (left < right) {
        int mid = left + (right - left) / 2;
        std::advance(it, mid - left);
        if (*it < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
        it = mainSequence.begin();
        std::advance(it, left);
    }
    return left;
}

void PmergeMe::insertIntoMainSequence(std::list<int>& mainSequence, int value, int end) {
    int position = binarySearch(mainSequence, value, end);
    std::list<int>::iterator it = mainSequence.begin();
    std::advance(it, position);
    mainSequence.insert(it, value);
}

void PmergeMe::mergeInsertionSort(std::list<int>& inputList) {
    std::list<std::pair<int, int> > pairs;
    std::list<int> mainSequence;
    std::list<int> secondSequence;
    std::list<int>::iterator it = inputList.begin();

    if (inputList.size() <= 1) {
        return;
    }
    // Create pairs of elements. {Step 1}
    while (it != inputList.end()) {
        int first = *it;
        ++it;
        if (it != inputList.end()) {
            int second = *it;
            ++it;
            if (first > second) {
                pairs.push_back(std::make_pair(second, first));
            } else {
                pairs.push_back(std::make_pair(first, second));
            }
        } else {
            mainSequence.push_back(first);
        }
    }

    // Create a main sequence and a second sequence. {Step 2}
    for (std::list<std::pair<int, int> >::iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
        mainSequence.push_back(pairIt->first);
        secondSequence.push_back(pairIt->second);
    }

    // Sort the main sequence recursively. {Step 4}
    this->mergeInsertionSort(mainSequence);

    // Insert the second sequence into the main sequence using binary search. {Step 5}
    for (std::list<int>::iterator secondIt = secondSequence.begin(); secondIt != secondSequence.end(); ++secondIt) {
        insertIntoMainSequence(mainSequence, *secondIt, mainSequence.size());
    }
    inputList = mainSequence;
}
