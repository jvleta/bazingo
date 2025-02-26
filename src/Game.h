#ifndef GAME_H
#define GAME_H

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

#endif