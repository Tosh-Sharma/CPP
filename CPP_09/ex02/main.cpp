#include "PmergeMe.hpp"

void solveForDeque(std::deque<int> &inputDeque)
{
	PmergeMe		pmergeme;
	struct timeval	start, end;
	long			secondsDiff, microSecondsDiff, result;

	gettimeofday(&start, NULL);

	pmergeme.fordJohnsonMergeSort(inputDeque);
	gettimeofday(&end, NULL);
	secondsDiff = end.tv_sec - start.tv_sec;
	microSecondsDiff = end.tv_usec - start.tv_usec;
	result = (secondsDiff * 1000000) + microSecondsDiff;

	std::cout << "After:\t";
	if (inputDeque.size() > 4) {
		for (int i = 0; i < 4; i++)
			std::cout << inputDeque[i] << " ";
		std::cout << "[...]";
	}
	else {
		for (size_t i = 0; i < inputDeque.size(); i++)
			std::cout << inputDeque[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\nTime to process a range of " << inputDeque.size()
			<< " elements with std::deque : " << result  << " μs" << std::endl;
}

void solveForList(std::list<int> &inputList)
{
	PmergeMe		pmergeme;
	struct timeval	start, end;
	long			sec, micro, result;

	gettimeofday(&start, NULL);

	pmergeme.fordJohnsonMergeSort(inputList);
	gettimeofday(&end, NULL);

	// Subject does not require this but its good for testing.
	// std::cout << "After:\t";
	// if (inputList.size() > 4) {
	// 	int count = 0;
	// 	for (std::list<int>::iterator it = inputList.begin(); it != inputList.end() && count < 4; ++it, ++count)
	// 		std::cout << *it << " ";
	// 	std::cout << "[...]";
	// }
	// else {
	// 	for (std::list<int>::iterator it = inputList.begin(); it != inputList.end(); ++it)
	// 		std::cout << *it << " ";
	// }

	sec = end.tv_sec - start.tv_sec;
	micro = end.tv_usec - start.tv_usec;
	result = (sec * 1000000) + micro;

	std::cout << "\nTime to process a range of " << inputList.size()
			<< " elements with std::list : " << result  << " μs" << std::endl;
}

int main(int argc, char *argv[])
{
	std::deque<int> inputDeque;
	std::list<int>  inputList;

	if (argc < 2) {
		std::cerr << "Error: Invalid Input: No Arguments\n";
		return 1;
	}
	if (argc == 2) {
		std::cerr << "Error: Invalid Input: Only 1 Argument\n";
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		if (isdigit(*argv[i]) && std::atoi(argv[i]) >= 0)
		{
			inputDeque.push_back(std::atoi(argv[i]));
			inputList.push_back(std::atoi(argv[i]));
		}
		else
		{
			std::cerr << "Error: Invalid Input\n";
			return 1;
		}
	}
	std::cout << "Before:\t";
	if (argc < 5) {
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
	} else {
		for (int i = 1; i < 5; i++)
			std::cout << argv[i] << " ";
	}
	if (argc > 5)
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;

	solveForDeque(inputDeque);
	solveForList(inputList);

	return 0;
}