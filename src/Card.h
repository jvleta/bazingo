#ifndef CARD_H
#define CARD_H

#include "Column.h"
#include "Game.h"
#include <vector>

struct Card {
  Column b_squares{1, 15};
  Column i_squares{16, 30};
  Column n_squares{31, 45};
  Column g_squares{46, 60};
  Column o_squares{61, 75};
  std::vector<Column *> columns{&b_squares, &i_squares, &n_squares, &g_squares,
                                &o_squares};
  friend std::ostream &operator<<(std::ostream &os, const Card &card);
  void update(int n);
  bool is_a_winner(Game game);

private:
  bool is_whole_card_covered();
  bool is_row_covered(int n);
  bool is_column_covered(int n);
  bool is_any_row_covered();
  bool is_any_column_covered();
  bool is_left_diagonal_covered();
  bool is_right_diagonal_covered();
  bool is_letter_x_covered();
  bool is_rotating_l_covered();
};

#endif