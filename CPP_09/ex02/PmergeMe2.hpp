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

		std::deque<int>	generateJacobsthal(int n);

		int		binarySearch(const std::deque<int>& main_chain, int b, int end);
		void	insertIntoMainChain(std::deque<int>& main_chain, int b, int end);
		void	mergeInsertionSort(std::deque<int>& vec);
};
