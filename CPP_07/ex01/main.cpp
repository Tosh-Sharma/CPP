#include "iter.hpp"

void    increment(int &n) {
    ++n;
}

int main() {
    int array[] = { 100, 101, 102, 103, 104 };
    iter(array, 5, increment);
    iter(array, 5, display);

    std::cout << "\n";

	char a[] = {'A', 'B', 'C'};
    iter(a, 3, display);

    std::cout << "\n";

    NumberClass numbers[5] = {
        NumberClass(22),
        NumberClass(33),
        NumberClass(44),
        NumberClass(55),
        NumberClass(66)
    };

    iter(numbers, 5, display);
    return 0;
}
