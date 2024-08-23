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

// Ford johnson algorithm for deque
void PmergeMe::fordJohnsonMergeSort(std::deque<int>& deque) {
    std::deque<int> sortedDeque;
    
    if (deque.size() <= 1) {
        return ;
    }    
    fordJohnsonMergeSortUtil(deque, sortedDeque);
    deque = sortedDeque;
}

void PmergeMe::fordJohnsonMergeSortUtil(std::deque<int>& deque, std::deque<int>& result) {
    std::deque<int> sortedSmaller;
    std::deque<int> sortedLarger;
    std::deque<int> smaller;
    std::deque<int> larger;

    if (deque.size() <= 1) {
        result = deque;
        return ;
    }
    for (size_t i = 0; i < deque.size(); i += 2) {
        if (i + 1 < deque.size()) {
            if (deque[i] < deque[i + 1]) {
                smaller.push_back(deque[i]);
                larger.push_back(deque[i + 1]);
            } else {
                smaller.push_back(deque[i + 1]);
                larger.push_back(deque[i]);
            }
        } else {
            smaller.push_back(deque[i]);
        }
    }
    fordJohnsonMergeSortUtil(smaller, sortedSmaller);
    fordJohnsonMergeSortUtil(larger, sortedLarger);
    merge(sortedSmaller, sortedLarger, result);
}

void PmergeMe::merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& mergeDeque) {
    std::deque<int>::iterator itLeft = left.begin();
    std::deque<int>::iterator itRight = right.begin();
    std::deque<int>::iterator itLeftEnd = left.end();
    std::deque<int>::iterator itRightEnd = right.end();

    while (itLeft != itLeftEnd && itRight != itRightEnd) {
        if (*itLeft <= *itRight) {
            mergeDeque.push_back(*itLeft);
            ++itLeft;
        } else {
            mergeDeque.push_back(*itRight);
            ++itRight;
        }
    }
    while (itLeft != itLeftEnd) {
        mergeDeque.push_back(*itLeft);
        ++itLeft;
    }
    while (itRight != itRightEnd) {
        mergeDeque.push_back(*itRight);
        ++itRight;
    }
}

// Ford johnson algorithm for std::list
void PmergeMe::fordJohnsonMergeSort(std::list<int>& lst) {
    std::list<int> sortedList;
    
    if (lst.size() <= 1) {
        return;
    }    
    fordJohnsonMergeSortUtil(lst, sortedList);
    lst = sortedList;
}

void PmergeMe::fordJohnsonMergeSortUtil(std::list<int>& lst, std::list<int>& result) {
    std::list<int> sortedSmaller;
    std::list<int> sortedLarger;
    std::list<int> smaller;
    std::list<int> larger;

    if (lst.size() <= 1) {
        result = lst;
        return;
    }
    
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        std::list<int>::iterator next = it;
        ++next;
        if (next != lst.end()) {
            if (*it < *next) {
                smaller.push_back(*it);
                larger.push_back(*next);
            } else {
                smaller.push_back(*next);
                larger.push_back(*it);
            }
            ++it;
        } else {
            smaller.push_back(*it);
        }
        ++it;
    }
    fordJohnsonMergeSortUtil(smaller, sortedSmaller);
    fordJohnsonMergeSortUtil(larger, sortedLarger);
    merge(sortedSmaller, sortedLarger, result);
}

void PmergeMe::merge(std::list<int>& left, std::list<int>& right, std::list<int>& mergeList) {
    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itRight = right.begin();
    std::list<int>::iterator itLeftEnd = left.end();
    std::list<int>::iterator itRightEnd = right.end();

    while (itLeft != itLeftEnd && itRight != itRightEnd) {
        if (*itLeft <= *itRight) {
            mergeList.push_back(*itLeft);
            ++itLeft;
        } else {
            mergeList.push_back(*itRight);
            ++itRight;
        }
    }
    while (itLeft != itLeftEnd) {
        mergeList.push_back(*itLeft);
        ++itLeft;
    }
    while (itRight != itRightEnd) {
        mergeList.push_back(*itRight);
        ++itRight;
    }
}
