#include "Square.h"

Square::Square(int n) {
  value_ = n;
  display_value_ = std::to_string(n);
  if (display_value_.size() < 2) {
    display_value_ = " " + display_value_;
  }
}

std::ostream &operator<<(std::ostream &os, const Square &square) {
  os << (square.is_daubed_ ? " *" : square.display_value_);
  return os;
}
