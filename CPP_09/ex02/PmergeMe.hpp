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
    private:
        void    fordJohnsonMergeSortUtil(std::deque<int>& deq,
                    std::deque<int>& result);
        void    merge(std::deque<int>& left, std::deque<int>& right,
                    std::deque<int>& mergeDeque);

        void    fordJohnsonMergeSortUtil(std::list<int>& lst,
                    std::list<int>& result);
        void    merge(std::list<int>& left, std::list<int>& right,
                    std::list<int>& mergeList);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe & other);
        PmergeMe & operator=(const PmergeMe & other);

        void    fordJohnsonMergeSort(std::deque<int>& deque);
        void    fordJohnsonMergeSort(std::list<int>& lst);
};
