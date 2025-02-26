#include "Column.h"
#include "utils.h"

Column::Column(std::vector<int> values) {
  for (auto value : values) {
    squares.emplace_back(value);
  }
}

Column::Column(int min, int max) : Column(get_shuffled_integers(min, max, 5)) {}

Square &Column::operator[](size_t index) { return squares[index]; }
const Square &Column::operator[](size_t index) const { return squares[index]; }
