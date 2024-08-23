#pragma once

#include <iostream>
#include <sys/time.h>
#include <list>
#include <deque>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe & other);
        PmergeMe & operator=(const PmergeMe & other);

		void	mergeInsertionSort(std::deque<int>& inputDeque);
		void	insertIntoMainSequence(std::deque<int>& mainSequence, int value, int end);
		int		binarySearch(const std::deque<int>& mainSequence, int value, int end);

        void    mergeInsertionSort(std::list<int>& inputList);
        void    insertIntoMainSequence(std::list<int>& mainSequence, int value, int end);
        int     binarySearch(const std::list<int>& mainSequence, int value, int end);
};
