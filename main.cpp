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
  os << (square.is_daubed ? " *" : square.display_value);
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

enum class Game {
  WholeCardCovered,
  Row1Covered,
  Row2Covered,
  Row3Covered,
  Row4Covered,
  Row5Covered,
  AnyRowCovered,
  BColumnCovered,
  IColumnCovered,
  NColumnCovered,
  GColumnCovered,
  OColumnCovered,
  AnyColumnCovered,
  LeftDiagonalCovered,
  RightDiagonalCovered,
  LetterX,
  RotatingL
};

struct Card {
  Column b_squares{1, 15};
  Column i_squares{16, 30};
  Column n_squares{31, 45};
  Column g_squares{46, 60};
  Column o_squares{61, 75};
  std::vector<Column *> columns{&b_squares, &i_squares, &n_squares, &g_squares,
                                &o_squares};
  friend std::ostream &operator<<(std::ostream &os, const Card &card);
  void update(int n) {
    for (auto &column : columns) {
      for (auto &square : column->squares) {
        if (square.value == n) {
          square.is_daubed = true;
        }
      }
    }
  }

  bool is_a_winner(Game game) {
    switch (game) {
    case Game::WholeCardCovered:
      return is_whole_card_covered();
    case Game::Row1Covered:
      return is_row_covered(0);
    case Game::Row2Covered:
      return is_row_covered(1);
    case Game::Row3Covered:
      return is_row_covered(2);
    case Game::Row4Covered:
      return is_row_covered(3);
    case Game::Row5Covered:
      return is_row_covered(4);
    case Game::AnyRowCovered:
      return is_any_row_covered();
    case Game::BColumnCovered:
      return is_column_covered(0);
    case Game::IColumnCovered:
      return is_column_covered(1);
    case Game::NColumnCovered:
      return is_column_covered(2);
    case Game::GColumnCovered:
      return is_column_covered(3);
    case Game::OColumnCovered:
      return is_column_covered(4);
    case Game::AnyColumnCovered:
      return is_any_column_covered();
    case Game::LeftDiagonalCovered:
      return is_left_diagonal_covered();
    case Game::RightDiagonalCovered:
      return is_right_diagonal_covered();
    case Game::LetterX:
      return is_letter_x_covered();
    case Game::RotatingL:
      return is_rotating_l_covered();
    }
    return true;
  }

private:
  bool is_whole_card_covered() {
    for (auto &column : columns) {
      for (auto &square : column->squares) {
        if (!square.is_daubed) {
          return false;
        }
      }
    }
    return true;
  }

  bool is_row_covered(int n) {
    for (auto &column : columns) {
      if (!column->squares[n].is_daubed) {
        return false;
      }
    }
    return true;
  }

  bool is_column_covered(int n) {
    for (auto &square : columns[n]->squares) {
      if (!square.is_daubed) {
        return false;
      }
    }
    return true;
  }

  bool is_any_row_covered() {
    for (int i = 0; i < 5; ++i) {
      if (is_row_covered(i)) {
        return true;
      }
    }
    return false;
  }

  bool is_any_column_covered() {
    for (int i = 0; i < 5; ++i) {
      if (is_column_covered(i)) {
        return true;
      }
    }
    return false;
  }

  bool is_left_diagonal_covered() {
    return b_squares[0].is_daubed && i_squares[1].is_daubed &&
           n_squares[2].is_daubed && g_squares[3].is_daubed &&
           o_squares[4].is_daubed;
  };

  bool is_right_diagonal_covered() {
    return b_squares[4].is_daubed && i_squares[3].is_daubed &&
           n_squares[2].is_daubed && g_squares[1].is_daubed &&
           o_squares[0].is_daubed;
  };

  bool is_letter_x_covered() {
    return is_left_diagonal_covered() && is_right_diagonal_covered();
  };

  bool is_rotating_l_covered() {
    return (is_column_covered(0) && is_row_covered(4)) ||
           (is_row_covered(4) && is_column_covered(4)) ||
           (is_column_covered(4) && is_row_covered(0)) ||
           (is_row_covered(0) && is_column_covered(0));
  }
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
  int num_wins = 0;
  int num_sims = 10000;
  int min_number_of_calls = 75;

  for (int n = 0; n < num_sims; ++n) {
    Card card{};
    card.n_squares[2].is_daubed = true;
    auto balls = get_shuffled_integers(1, 75, 75);
    for (int i = 1; i <= balls.size(); ++i) {
      card.update(balls[i - 1]);
      if (card.is_a_winner(Game::RotatingL)) {
        std::cout << i << "\n";
        min_number_of_calls = std::min(i, min_number_of_calls);
        break;
      }
    }
  }
  std::cout << min_number_of_calls << " \n";
}
