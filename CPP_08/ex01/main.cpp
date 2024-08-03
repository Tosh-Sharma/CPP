#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
    Span(unsigned int N) : max_size(N) {}

    void addNumber(int number) {
        if (numbers.size() >= max_size) {
            throw std::out_of_range("Span is already full.");
        }
        numbers.push_back(number);
    }

    int shortestSpan() {
        if (numbers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }

        std::vector<int> sorted_numbers(numbers);
        std::sort(sorted_numbers.begin(), sorted_numbers.end());

        int min_span = sorted_numbers[1] - sorted_numbers[0];
        for (size_t i = 1; i < sorted_numbers.size() - 1; ++i) {
            int span = sorted_numbers[i + 1] - sorted_numbers[i];
            if (span < min_span) {
                min_span = span;
            }
        }
        return min_span;
    }

    int longestSpan() {
        if (numbers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }

        auto [min_it, max_it] = std::minmax_element(numbers.begin(), numbers.end());
        return *max_it - *min_it;
    }

private:
    std::vector<int> numbers;
    unsigned int max_size;
};

int main() {
    try {
        Span sp(10);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(50);
        sp.addNumber(1000);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}