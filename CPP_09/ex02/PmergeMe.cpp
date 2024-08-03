#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <chrono>

void mergeInsertSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    if (arr.size() < 64) { // Insert sort for small arrays
        for (size_t i = 1; i < arr.size(); ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    } else { // Merge sort for larger arrays
        size_t mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());
        mergeInsertSort(left);
        mergeInsertSort(right);
        std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
    }
}

void mergeInsertSort(std::deque<int>& arr) {
    if (arr.size() <= 1) return;
    if (arr.size() < 64) { // Insert sort for small arrays
        for (size_t i = 1; i < arr.size(); ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    } else { // Merge sort for larger arrays
        size_t mid = arr.size() / 2;
        std::deque<int> left(arr.begin(), arr.begin() + mid);
        std::deque<int> right(arr.begin() + mid, arr.end());
        mergeInsertSort(left);
        mergeInsertSort(right);
        std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No positive integer sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    try {
        for (int i = 1; i < argc; ++i) {
            int num = std::stoi(argv[i]);
            if (num <= 0) {
                throw std::invalid_argument("Error: All numbers must be positive integers.");
            }
            vec.push_back(num);
            deq.push_back(num);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_vec = end - start;

    std::cout << "After: ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process range of 5 elements with std::[..]: " << duration_vec.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(deq);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_deq = end - start;

    std::cout << "Time to process range of 5 elements with std::[..]: " << duration_deq.count() << " seconds" << std::endl;

    return 0;
}
