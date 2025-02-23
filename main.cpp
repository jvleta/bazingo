#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

struct std::vector<int> get_shuffled_integers(int start, int stop,
                                              int subset_size) {
  const int size = (stop - start) + 1;
  std::vector<int> numbers(size);
  std::iota(numbers.begin(), numbers.end(), start);
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(numbers.begin(), numbers.end(), rng);
  return std::vector<int>(numbers.begin(), numbers.begin() + subset_size);
}

struct Square {
  int value = 0;
  std::string display_value{};
  bool is_daubed = false;
  Square(int n) {
    value = n;
    display_value = std::to_string(n);
    if (display_value.size() < 2) {
      display_value = " " + display_value;
    }
  }
  friend std::ostream &operator<<(std::ostream &os, const Square &square);
};

std::ostream &operator<<(std::ostream &os, const Square &square) {
  os << square.display_value;
  return os;
}

struct Column {
  std::vector<Square> squares;
  Column(std::vector<int> values) {
    for (auto value : values) {
      squares.emplace_back(value);
    }
  }
  Column(int min, int max) : Column(get_shuffled_integers(min, max, 5)) {}
  Square &operator[](size_t index) { return squares[index]; }

  const Square &operator[](size_t index) const { return squares[index]; }
};

struct Card {
  Column b_squares{1, 15};
  Column i_squares{16, 30};
  Column n_squares{31, 45};
  Column g_squares{46, 60};
  Column o_squares{61, 75};
  friend std::ostream &operator<<(std::ostream &os, const Card &card);
};

std::ostream &operator<<(std::ostream &os, const Card &card) {
  os << " B  I  N  G  O\n"; // Header
  for (int index = 0; index < 5; ++index) {
    os << card.b_squares[index] << " " << card.i_squares[index] << " "
       << card.n_squares[index] << " " << card.g_squares[index] << " "
       << card.o_squares[index] << "\n";
  }
  return os;
}

int main() {
  std::cout << "hi mom!!!\n";
  Card card{};
  std::cout << card;
}
