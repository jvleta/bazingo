#include "Card.h"
#include "Square.h"
#include "Game.h"

void Card::update(int n) {
  for (auto &column : columns) {
    for (auto &square : column->squares) {
      if (square.get_value() == n) {
        square.daub();
      }
    }
  }
}

bool Card::is_a_winner(Game game) {
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

bool Card::is_whole_card_covered() {
  for (auto &column : columns) {
    for (auto &square : column->squares) {
      if (!square.is_daubed()) {
        return false;
      }
    }
  }
  return true;
}

bool Card::is_row_covered(int n) {
  for (auto &column : columns) {
    if (!column->squares[n].is_daubed()) {
      return false;
    }
  }
  return true;
}

bool Card::is_column_covered(int n) {
  for (auto &square : columns[n]->squares) {
    if (!square.is_daubed()) {
      return false;
    }
  }
  return true;
}

bool Card::is_any_row_covered() {
  for (int i = 0; i < 5; ++i) {
    if (is_row_covered(i)) {
      return true;
    }
  }
  return false;
}

bool Card::is_any_column_covered() {
  for (int i = 0; i < 5; ++i) {
    if (is_column_covered(i)) {
      return true;
    }
  }
  return false;
}

bool Card::is_left_diagonal_covered() {
  return b_squares[0].is_daubed() && i_squares[1].is_daubed() &&
         n_squares[2].is_daubed() && g_squares[3].is_daubed() &&
         o_squares[4].is_daubed();
}

bool Card::is_right_diagonal_covered() {
  return b_squares[4].is_daubed() && i_squares[3].is_daubed() &&
         n_squares[2].is_daubed() && g_squares[1].is_daubed() &&
         o_squares[0].is_daubed();
}

bool Card::is_letter_x_covered() {
  return is_left_diagonal_covered() && is_right_diagonal_covered();
}

bool Card::is_rotating_l_covered() {
  return (is_column_covered(0) && is_row_covered(4)) ||
         (is_row_covered(4) && is_column_covered(4)) ||
         (is_column_covered(4) && is_row_covered(0)) ||
         (is_row_covered(0) && is_column_covered(0));
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
  os << " B  I  N  G  O\n"; // Header
  for (int index = 0; index < 5; ++index) {
    os << card.b_squares[index] << " " << card.i_squares[index] << " "
       << card.n_squares[index] << " " << card.g_squares[index] << " "
       << card.o_squares[index] << "\n";
  }
  return os;
}
