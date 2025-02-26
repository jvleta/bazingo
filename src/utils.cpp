#include "utils.h"
#include <algorithm>
#include <random>
#include <vector>

std::vector<int> get_shuffled_integers(int min, int max, int count) {
    std::vector<int> numbers;
    for (int i = min; i <= max; ++i) {
        numbers.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);
    numbers.resize(count);
    return numbers;
}
