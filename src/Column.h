#ifndef COLUMN_H
#define COLUMN_H

#include "Square.h"
#include <vector>

struct Column {
  std::vector<Square> squares;
  Column(std::vector<int> values);
  Column(int min, int max);
  Square &operator[](size_t index);
  const Square &operator[](size_t index) const;
};

#endif