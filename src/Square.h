#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>

class Square {
public:
  Square(int n);
  bool is_daubed() { return is_daubed_; }
  std::string get_display_value() { return display_value_; }
  int get_value() { return value_; }
  friend std::ostream &operator<<(std::ostream &os, const Square &square);
  void daub() { is_daubed_ = true; }

private:
  int value_;
  std::string display_value_;
  bool is_daubed_ = false;
};

#endif // SQUARE_H
